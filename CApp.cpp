//==============================================================================
#include "CApp.h"
#include <iostream>

using namespace std;

//==============================================================================
CApp::CApp(string& f) : filename(f) {
    Surf_Test = NULL;
    Surf_Display = NULL;

    Running = true;
}

//------------------------------------------------------------------------------
int CApp::OnExecute() {
    if(OnInit() == false) {
        return -1;
    }

    SDL_Event Event;

    while(Running) {
        while(SDL_PollEvent(&Event)) {
            OnEvent(&Event);
        }

        OnLoop();
        OnRender();
    }

    OnCleanup();

    return 0;
}

//==============================================================================
int main(int argc, char* argv[]) {

    if (argc < 2) {
        cerr << "A filename argument is required" << endl;
        return 1;
    }

    string s(argv[1]);

    CApp theApp(s);
    
    return theApp.OnExecute();
}

//==============================================================================
