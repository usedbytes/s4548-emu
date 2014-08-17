//==============================================================================
// SDL Tutorial 1
//==============================================================================
#ifndef _CAPP_H_
    #define _CAPP_H_

#include <SDL.h>
#include <string>
#include "CSurface.h"

//==============================================================================

#define WIDTH 101
#define HEIGHT 40
//#define FILE_SIZE (WIDTH * (HEIGHT / 8))
#define FILE_SIZE 4096

class CApp {
    private:
        bool            Running;

        SDL_Surface*    Surf_Display;

        SDL_Surface*	Surf_Test;
        
        std::string filename;
        int fd;
        char * mem;

    public:
        CApp(std::string& f);

        int OnExecute();

    public:
        bool OnInit();

        void OnEvent(SDL_Event* Event);

        void OnLoop();

        void OnRender();

        void OnCleanup();
};

//==============================================================================

#endif
