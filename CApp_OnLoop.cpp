//==============================================================================
#include "CApp.h"
#include <iostream>
#include <stdint.h>
//==============================================================================

using namespace std;

const unsigned char BITMASKS[] = { 0x80, 0x40, 0x20, 0x10, 0x8, 0x4, 0x2, 0x1 };
const uint32_t black = 0x0;
const uint32_t white = 0xFFFFFFFF;

void CApp::OnLoop() {
    
    
    if (SDL_MUSTLOCK(Surf_Display)) {
        SDL_LockSurface(Surf_Display);
    }

    uint32_t * pixdata = (uint32_t *)Surf_Display->pixels;
    
    for (int y(0); y < HEIGHT; y++) {
        int pixel_offset = y * WIDTH;
        int row_offset = (y / 8) * WIDTH;
        
        for (int x(0); x < WIDTH; x++) {
            if (mem[row_offset + x] & BITMASKS[y % 8]) {
                // set pixel x,y
                pixdata[pixel_offset + x] = black;
            } else {
                // clear pixel x,y
                pixdata[pixel_offset + x] = white;
            }
        } 
    }
    
    //pixdata[101] = white;
    
    if (SDL_MUSTLOCK(Surf_Display)) {
        SDL_UnlockSurface(Surf_Display);
    }
    
}

//==============================================================================
