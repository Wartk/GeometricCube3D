#define SDL_MAIN_HANDLED

#include <SDL2/SDL.h>
#include <iostream>
#include <vector>
#include "Math/matriz.h"

using namespace std;

float angle = 0.002;
float cube_scale = 150;
Vector3 screen_size = {800, 600, 0};

int main(int argc, char* args[]) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("Geometric Cube", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screen_size.x, screen_size.y, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);


    vector<Vector3> vert = {
        Vector3(1,-1,1),
        Vector3(1,1,1),
        Vector3(1,1,-1),
        Vector3(1,-1,-1),
        Vector3(-1,-1,1),
        Vector3(-1,1,1),
        Vector3(-1,1,-1),
        Vector3(-1,-1,-1),
    };
    

    //Center
    for(int i = 0; i < 8; i++){
        vert[i].x = cube_scale * vert[i].x + (screen_size.x / 2); 
        vert[i].y = cube_scale * vert[i].y + (screen_size.y / 2); 
        vert[i].z = cube_scale * vert[i].z + (screen_size.z / 2);
    }

    bool running = true;
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        Matrix3x3 _rotationY_ = rotationY(angle);
        Matrix3x3 _rotationZ_ = rotationZ(angle);

        for(int i = 0; i < 8; i++){
            vert[i] = Vectors.add(vert[i], Vector3(-screen_size.x / 2, -screen_size.y / 2, 0));
            vert[i] = Multi(_rotationY_, vert[i]);
            vert[i] = Multi(_rotationZ_, vert[i]);
            vert[i] = Vectors.add(vert[i], Vector3(screen_size.x / 2, screen_size.y / 2, 0));
        }


        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

        for (int i = 0; i < 4; i++) {
            SDL_RenderDrawLine(renderer, vert[i].x, vert[i].y, vert[(i + 1) % 4].x, vert[(i + 1) % 4].y);
        }

        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);

        for(int i = 4; i < 7; i++){
            SDL_RenderDrawLine(renderer, vert[i].x, vert[i].y, vert[(i + 1)].x, vert[(i + 1)].y);
        }
        SDL_RenderDrawLine(renderer, vert[7].x, vert[7].y, vert[4].x, vert[4].y);


        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

        for (int i = 0; i < 4; i++) {
            SDL_RenderDrawLine(renderer, vert[i].x, vert[i].y, vert[i + 4].x, vert[i + 4].y);
        }

        SDL_RenderPresent(renderer);

        SDL_Delay(4);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}