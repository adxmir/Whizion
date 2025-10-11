#include "MainWindow.hpp"

MainWindow::MainWindow(unsigned int x, unsigned int y){
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("Whizion",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, x, y, SDL_WINDOW_SHOWN);

    if(!window){
        std::cerr << "Failed to create window : " << SDL_GetError() << "\n";
        throw std::runtime_error("Failed to create winow");
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);

    if(TTF_Init() == -1){
        std::cerr << "TTF failure: " << TTF_GetError() << "\n";
        closeWindow();
    }
    
    if(!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)){
        std::cerr << "IMG Error: " << IMG_GetError() << "\n";
        closeWindow();
    }
    SDL_RenderClear(renderer);

    TTF_Font* font = TTF_OpenFont("src/UI/fonts/tothepoint.ttf", 20);
    if(!font){
        std::cerr << "Failed to load font: " << TTF_GetError() << "\n";
        closeWindow();
    }
    SDL_Color textColor = {255,255,255,255};
    int width = 40;
    int height = 20;
    const char* text = "Whizion";
    TTF_SizeText(font, text, &width, &height);

    SDL_Surface* surface = TTF_RenderText_Solid(font, text, textColor);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    SDL_Rect textRect = {100, 50 , width, height};
    SDL_RenderCopy(renderer, texture, nullptr, &textRect);
    SDL_RenderPresent(renderer);
    //SDL_DestroyTexture(texture);

}


void MainWindow::closeWindow(){
    if(renderer){
        SDL_DestroyRenderer(renderer);
        renderer = nullptr;
    }
    if(window){
        SDL_DestroyWindow(window);
        window = nullptr;
    }
    IMG_Quit();
    SDL_Quit();
}

