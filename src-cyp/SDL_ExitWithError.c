#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include <stdlib.h>

void SDL_ExitWithError(const char *message)
{
SDL_Log("ERREUR : %s > %s\n", message, SDL_GetError());
SDL_Quit();
exit(EXIT_FAILURE);
}
