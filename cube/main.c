#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <stdbool.h>


#define WIDTH 800
#define HEIGHT 600


typedef struct{
  float x, y, z;
}Point3D;


typedef struct{
  int x, y;
}Point2D;

Point2D cordenadas(Point3D p){
  int x = (p.x * 200) + 400;
  int y = ((p.y * 200) * -1) + 300;

  Point2D p22;
  p22.x = x;
  p22.y = y;

  return p22;
}

int main(){
  SDL_Init(SDL_INIT_VIDEO);
  SDL_Window* window = SDL_CreateWindow(
    "Janela",
    SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED,
    WIDTH, HEIGHT,
    SDL_WINDOW_SHOWN
  );
  
  SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  SDL_Event e;

  float z1 = 1.0f;
  float z2 = -1.0f;
  Point3D cube[8] = {
    {1, 1, z1},
    {1, -1, z1},
    {-1, 1, z1},
    {-1, -1, z1},
    {1, 1, z2},
    {1, -1, z2},
    {-1, 1, z2},
    {-1, -1, z2}

  };

  bool runing = false;
  while (!runing) {


  SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
  SDL_RenderClear(renderer);
  SDL_RenderPresent(renderer);
    while(SDL_PollEvent(&e)){
      if(e.type == SDL_QUIT){
        runing = true;
      }
    }
  
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
