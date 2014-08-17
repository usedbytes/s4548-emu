//==============================================================================
#include "CApp.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

using namespace std;
//==============================================================================
bool CApp::OnInit() {
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }

    char * ptr = (char*)malloc(FILE_SIZE);
    if (ptr == NULL) {
        cerr << "Unable to allocate a buffer" << endl;
        return false;
    }
    memset(ptr, 0xAA, FILE_SIZE);

    fd = open(filename.c_str(), O_RDWR | O_TRUNC | O_CREAT, S_IRUSR | S_IWUSR);
    if (write(fd, ptr, FILE_SIZE) != FILE_SIZE) {
        cerr << "Unable to write to file" << endl;
        close(fd);
	free(ptr);
        return false;
    }
    free(ptr);
    
	cout << "ptr: " << (void *)ptr << endl;
    mem = (char *)mmap(0, FILE_SIZE, PROT_READ | PROT_WRITE, MAP_FILE|MAP_SHARED, fd, 0);
	cout << "mem: " << (void *)mem << endl;
    if (mem == MAP_FAILED) {
        cerr << "Map Failed" << endl;
        close(fd);
	return false;
    }
    
    if((Surf_Display = SDL_SetVideoMode(WIDTH, HEIGHT, 32, SDL_SWSURFACE)) == NULL) {
        return false;
    }

    /*
	if((Surf_Test = CSurface::OnLoad("myimage.bmp")) == NULL) {
		return false;
	}
    */
    return true;
}

//==============================================================================
