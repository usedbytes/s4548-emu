//==============================================================================
#include "CApp.h"
#include <iostream>
//==============================================================================
void CApp::OnRender() {
	
	//std::cout << "OnRender" << std::endl;
	//CSurface::OnDraw(Surf_Display, Surf_Test, 0, 0);
	//CSurface::OnDraw(Surf_Display, Surf_Test, 100, 100, 0, 0, 50, 50);

	SDL_Flip(Surf_Display);
}

//==============================================================================
