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

    const char* text = "Whizion";
    makeText(text, 64, x/2, y/2-50);

    const char* desc_text = "Be prepared to test your reaction time, problem solving skills and adaptability";
    makeText(desc_text, 20, int(x/2), int(y/2) + 60);

    SDL_RenderPresent(renderer);
}

void MainWindow::makeText(const char* text, int size , int x , int y){
    SDL_Color textColor = {255,255,255,255};
    std::shared_ptr<TTF_Font> font = std::shared_ptr<TTF_Font>(TTF_OpenFont("/Users/alidemir/Documents/PersonalProjects/Whizion/src/UI/fonts/RubikBubbles-Regular.ttf", size), TTF_CloseFont);
    
    
    SDL_Surface* text_surface = TTF_RenderText_Blended_Wrapped(font.get(), text, textColor, 600);
    SDL_Texture* text_texture = SDL_CreateTextureFromSurface(renderer, text_surface);
    SDL_Rect textRect = {int(x - text_surface->w/2), int(y - text_surface->h/2), text_surface->w, text_surface->h};

    SDL_FreeSurface(text_surface);
    SDL_RenderCopy(renderer, text_texture, nullptr, &textRect);
    SDL_DestroyTexture(text_texture);
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

