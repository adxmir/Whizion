#include <iostream>
#include "src/UI/MainWindow.hpp"

using namespace std;


int main(){

    bool running = true;
    MainWindow mainWindow(720, 560);
    
    while(running){
        SDL_Event event;
        while(SDL_PollEvent(&event)){
            switch(event.type){
                case SDL_QUIT:
                    running = false;
                    break;
                default:
                    break;
            }
        }
        SDL_Delay(50);
    }

    return 0;
}