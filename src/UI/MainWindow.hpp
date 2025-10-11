#ifndef MAINW_H
#define MAINW_H
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_ttf.h>
#include <cerrno>


class MainWindow{
public:
    MainWindow(unsigned int x, unsigned int y);
    ~MainWindow(){closeWindow();}

private:
  SDL_Window* window;
  SDL_Renderer* renderer;

  void closeWindow();
};


#endif
