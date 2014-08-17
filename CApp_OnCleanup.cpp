//==============================================================================
#include "CApp.h"
#include <iostream>
//==============================================================================
void CApp::OnCleanup() {
    //SDL_FreeSurface(Surf_Test);
    SDL_FreeSurface(Surf_Display);
    std::cout << "OnCleanup" << std::endl;
    SDL_Quit();
}

//==============================================================================
