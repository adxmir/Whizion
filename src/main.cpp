#include <iostream>
#include "src/UI/MainWindow.hpp"
#include "src/UI/button.hpp"

using namespace std;


int main(){
    Mouse mouse;
    bool running = true;
    MainWindow mainWindow(720, 560);
    Button startButton();
    
    while(running){
        SDL_Event event;
        while(SDL_PollEvent(&event)){
            switch(event.type){
                case SDL_QUIT:
                    running = false;
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    mouse.update();
                default:
                    break;
            }
        }
        SDL_Delay(50);
    }

    return 0;
}