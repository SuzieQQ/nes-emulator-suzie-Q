#include "Typedef.h"
#include "SDL2/SDL.h"


#define W 640
#define H 480




int main(int argc, char* argv[]) {

     /*  if (argc != 2) {

           std::cout << "\033[1;31mUsage: Nes <ROM file>\033[0m\n" << std::endl;
           return 1;
       }
*/
    SDL_Window *window;                   

    SDL_Init(SDL_INIT_VIDEO);              

window = SDL_CreateWindow("neSQ (Emulator)",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED, W,H,SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
SDL_Renderer *renderer = SDL_CreateRenderer(window, -1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);
SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );


//Make a target texture to render too
	SDL_Texture *texTarget = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888,
		SDL_TEXTUREACCESS_TARGET, W,H); 



    // Check that the window was successfully created
    if (window == NULL) {
        // In the case that the window could not be made...
        printf("Could not create window: %s\n", SDL_GetError());
        return 1;
    }


    bool keep_window_open = true;
    while(keep_window_open)
    {
        SDL_Event e;
        while(SDL_PollEvent(&e) > 0)
        {
            switch(e.type)
            {
                case SDL_QUIT:
                    keep_window_open = false;
                    break;         
            }

            if (e.type == SDL_KEYDOWN)
            {
                switch (e.key.keysym.sym)
                {
                case SDLK_ESCAPE:
              keep_window_open = false;
                case SDLK_F1:
                    break;
                case SDLK_F8:
        SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
               
                default:
                    break;
                }
            }
            

   SDL_SetTextureColorMod( texTarget, 64, 64, 64 );         
    SDL_RenderClear(renderer);
	SDL_RenderCopyEx(renderer, texTarget, NULL, NULL, 0, NULL, SDL_FLIP_VERTICAL);
	SDL_RenderPresent(renderer);
    SDL_UpdateWindowSurface(window);

        }

    }
   
   SDL_DestroyRenderer(renderer);
   SDL_DestroyWindow(window);
   SDL_Quit();
   return 0;
}


