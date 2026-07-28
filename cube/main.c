#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <math.h>
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
  float dist_camera = 4.0f;

  float x = (p.x * 200) / (dist_camera + p.z) + 400;
  int y = ((p.y * 200) * -1) / (dist_camera + p.z) + 300;

  Point2D p22;
  p22.x = x;
  p22.y = y;

  return p22;
}

Point3D rotacaoY(Point3D p, float angle){
  Point3D novo;

  novo.x = p.x * cos(angle) - p.z * sin(angle);
  novo.z = p.x * sin(angle) + p.z * cos(angle);
  novo.y = p.y;

  return novo;
}

int arestas[12][2] = {
{0,1},{2,3},{2,0},{3,1},
{4,5},{6,7},{6,4},{7,5},
{0,4},{1,5},{2,6},{3,7}
};

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


    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    for(int i=0; i<12; i++){
      int a = arestas[i][0];
      int b = arestas[i][1];
  
      Point2D pA = cordenadas(cube[a]);
      Point2D pB = cordenadas(cube[b]);

      SDL_RenderDrawLine(renderer, pA.x, pA.y, pB.x, pB.y);
    }

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
