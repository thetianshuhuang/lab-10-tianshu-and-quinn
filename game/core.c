/*
 * core.h
 *
 * Core game mechanics for Rock Band
 */

#include "core.h"
#include "../audio/driver.h"
#include "../tm4c123gh6pm.h"
#include "../controller/controller.h"
#include "../display/guitar.h"
#include "../PLL.h"
#include "../display/ST7735.h"
#include "../display/splash.h"
#include "songs.h"
#include "load_song.h"
#include "../controller/dsp.h"

GAME_STATE playerState;

Note testRed;
Note testYellow;
Note testBlue;
Note testGreen;
Note notes[20];

uint32_t noteIndex;

void incrementNotePointer(void){
	noteIndex++;
	if(noteIndex >= 20)
		noteIndex = 0;
}

// ----------selectInstrument----------
// Set the player's current instrument
// Parameters:
//      enum instrument_t instrument: instrument to choose; GUITAR, BASS, or DRUMS
void selectInstrument(enum instrument_t instrument) {
    playerState.instrument = instrument;
}


// Storage array for the current song
uint16_t currentTrack[2048];
// Tick tracker
uint16_t drawTicks;

// ----------initGame----------
// initialize game (start song)
// Parameters
//      SONG song: song to play
void initGame(SONG *song) {
    
    playerState.tick = song->length;
    playerState.score = 0;
    playerState.head = 0;
    playerState.headPtr = 0;
    playerState.percent = 0;
    drawTicks = 3500;

    // Zero out track
    for(int i = 0; i < 3072; i++) {
        currentTrack[i] = 0x03FF;
    }
    
    // Load song from SD card
    if(playerState.instrument == GUITAR) {
        loadSong(currentTrack, song->guitarTrack);
    }
    else if(playerState.instrument == BASS) {
        loadSong(currentTrack, song->bassTrack);
    }
    else if(playerState.instrument == DRUMS) {
        loadSong(currentTrack, song->drumsTrack);
    }
    // Null track
    else {}
    
    // Start song
    startSong(song->byteWav, &(playerState.tick));
}


// ----------findId----------
// Helper function to find the game state corresponding to an ID
// Parameters:
//      uint8_t id: id to find
// Returns:
//      uint8_t: index of found game states; 0xFF for error
uint8_t findId(uint8_t id) {
    for(uint8_t i = 0; i < 4; i++) {
        if(playerState.id == id) {
            return(i);
        }
    }
    return(0xFF);
}

uint16_t change;
uint16_t drawCtr;
// ----------mainLoop----------
// Main game loop
void mainLoop(void) {
    drawGuitar();

    // Start at normal play
    int32_t starCounter = 0;
    playerState.guitarState = NORMAL;
    drawCtr = 100;
    
    // Clear note States
    for(uint8_t i = 0; i < 4; i++) {
        noteStates[i] = 0;
    }
    
    // Play until tick overflows
    while(playerState.tick < 0x8FFFFFFF) {
        if(drawCtr == 0) {
            drawCtr = 10000;
            drawGuitar();
        }
        updatePickups(controllerRead());
        drawCtr --;
        GPIO_PORTF_DATA_R ^= 0x80;
        int16_t scoreChange;
        // Exempt drums from strumming
        if(playerState.instrument == DRUMS) {
            scoreChange = updateNote(0x1000, playerState.guitarState);
        }
        else {
            uint16_t change = derivative(controllerRead() & 0x0FFF);
            scoreChange = updateNote(change, playerState.guitarState);
        }
        // Update starpower
        if(playerState.guitarState == NORMAL) {
            starCounter += scoreChange;
            if(starCounter > 8000) {
                starCounter = 800;
                playerState.guitarState = STARPOWER;
                // Draw starpower
                ST7735_DrawLine(35, 0, 0, 160, COLOR_STARPOWER);
                ST7735_DrawLine(49, 0, 34, 160, COLOR_STARPOWER);
                ST7735_DrawFastVLine(64, 0, 160, COLOR_STARPOWER);
                ST7735_DrawLine(79, 0, 94, 160, COLOR_STARPOWER);
                ST7735_DrawLine(93, 0, 128, 160, COLOR_STARPOWER);
            }
            playerState.score += scoreChange;
        }
        if(playerState.guitarState == STARPOWER) {
            // Decrease star counter each cycle
            starCounter --;
            // Hits will extend the star counter; misses will decrease it
            if(scoreChange < 0) {
                starCounter += scoreChange;
            }
            else {
                starCounter += scoreChange / 20;
            }
            if(starCounter < 0) {
                playerState.guitarState = NORMAL;
                // Clear guitar
                ST7735_DrawLine(35, 0, 0, 160, COLOR_NORMAL);
                ST7735_DrawLine(49, 0, 34, 160, COLOR_NORMAL);
                ST7735_DrawFastVLine(64, 0, 160, COLOR_NORMAL);
                ST7735_DrawLine(79, 0, 94, 160, COLOR_NORMAL);
                ST7735_DrawLine(93, 0, 128, 160, COLOR_NORMAL);

            }
            playerState.score += 2 * scoreChange;
        }
        
        // Update score
        if(playerState.score > 60000) {
            playerState.score = 0;
        }
        updateScore(playerState.score);

        if(checkPause() != 0) {
            playerState.tick = 0xEFFFFFFF;
            break;
        }                
    }
    
    // End song
    endSong();
    
    showSplash("back.pi");
    ST7735_SetTextColor(0xFFFF);
    ST7735_SetCursor(3, 2);
    ST7735_OutString("Your Score:");
    ST7735_SetCursor(3, 3);
    ST7735_OutUDec(playerState.score);
    ST7735_SetCursor(3, 4);
    /*
    ST7735_OutString("Your Accuracy:");
    ST7735_SetCursor(3, 5);
    ST7735_OutUDec(playerState.score/playerState.percent);
    ST7735_OutString(" %");
    */
    // Wait for input
    while((controllerRead() & 0xF000) == 0){};
}


/*
// ----------updateGame----------
// Update game state over network
// Parameters:
//      uint8_t* packet: byte string packet
void updateGame(uint8_t* packet) {
    GAME_STATE *targetPlayer = &playerStates[findId(packet[2])];
    targetPlayer->score = ((uint16_t) packet[5] << 8) | packet[6];
    targetPlayer->currentOffset = ((uint16_t) packet[7] << 8) | packet[8];
    targetPlayer->tick = 
        (uint32_t) packet[9] << 24 |
        (uint32_t) packet[10] << 16 |
        (uint32_t) packet[11] << 8 |
        (uint32_t) packet[12];
}
*/


uint8_t ADCCounter;
// ----------Timer0A_Handler----------
// Timer handler for ADC sampling and SD read
void Timer0A_Handler(void) {

    GPIO_PORTF_DATA_R ^= 0x08;

    // Clear interrupt
    TIMER0_ICR_R = TIMER_ICR_TATOCINT;
    // Take ADC sample
    if(ADCCounter > 40) {
        sampleAdc();
        ADCCounter = 0;
    }
    // Read sector
    readSector();

    GPIO_PORTF_DATA_R ^= 0x08;
    ADCCounter += 1;
}


// ----------systick_Handler----------
void SysTick_Handler(void) {
    updateSong();
    // Increment note index when the next note is reached, and set remaining time
    if(playerState.head == 0) {
        do {
            playerState.head = 100 * (currentTrack[playerState.headPtr] & 0x03FF);
            playerState.headPtr += 1;
        } while(playerState.head == 0);
        // Create relevant notes
        createNotes(currentTrack[playerState.headPtr]);
    }
    if(drawTicks == 0) {
        drawTicks = 3500;
        moveNotes();
    }
    playerState.head -= 1;
    drawTicks -= 1;
}

