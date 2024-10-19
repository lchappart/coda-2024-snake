#include "snake.h"

int main()
{
    FILE *fp = fopen("map.txt", "r");

    char * file_content;
    char **tab;
    int lines;
    char * line;
    int i = 0;
    int j = 0;
    int direction = 0;
    int wincond = 1;
    int bonus = 50;
    int del = 100;
   
    srand(time(NULL));

    if (fp == NULL)
    {
        printf("Le fichier map.txt n'a pas pu être ouvert\n");
        return EXIT_FAILURE;
    }

    file_content = get_file(fp);
    fclose(fp);
    
    lines = count_lines(file_content);
    tab = malloc(lines * sizeof(*tab));
    line = strtok(file_content, "\n");
    
    while((line != NULL) && (i < lines))
    {
        tab[i] = malloc(strlen(line) * sizeof(char));
        tab[i] = strcpy(tab[i], line);
        i++;

        line = strtok(NULL, "\n");
    }

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0)
    {
        printf("Error SDL2 Init : %s\n", SDL_GetError());
        return 1;
    }

    if (IMG_Init(IMG_INIT_PNG) == 0) 
    {
        printf("Erreur d'initialisation de la SDL_Image\n");
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 320, SDL_WINDOW_OPENGL);

    if (window == NULL) 
    {
        printf("Error while creating a window : %s\n", SDL_GetError());
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) 
    {
        printf("Erreur à la création du renderer\n");
        return 1;
    }

    SDL_Surface* surface = IMG_Load("colors.png");
    if (surface == NULL) 
    {
        printf("Error loading image %s\n", IMG_GetError());
        return 1;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (texture == NULL) 
    {
        printf("Error creating texture\n");
        return 1;
    }

    SDL_FreeSurface(surface);   
    snake *list = create_list();
    fruit *list2 = create_list_fruit();
    
    for (int k = 1; k < 4; k++)
    {
        add_to_end(&list);
    }
    
        while(wincond)
        {
            
            bonus--;
            
            eat_fruit(&list, list2, tab);
            del = eat_bonus(&list, list2, tab, del);
            refresh_map(tab, list,list2);
            if(bonus == 1)
            {
                del = del - 80;
            }
            SDL_Event e;
            while (SDL_PollEvent(&e)) 
            {
                if (e.type == SDL_QUIT) 
                {
                    break;
                }
                else if (e.type == SDL_KEYDOWN)
                {
                    switch (e.key.keysym.sym)
                    {
                        case SDLK_UP:
                            if (direction != 3) direction = 2;
                        break;
                        case SDLK_DOWN:
                            if (direction != 2) direction = 3;
                        break;
                        case SDLK_LEFT:
                            if (direction != 0) direction = 1;
                        break;
                        case SDLK_RIGHT:
                            if (direction != 1) direction = 0;
                        break;
                    }
                }
            }
            SDL_Delay(del);
            move(&list, direction);
            wincond = wincondition(&list);
            SDL_RenderClear(renderer);
            i = 0;
            while(i < lines)
            {
                j = 0;
                while(j < 40)
                {
                    if(tab[i][j] == '0')
                    {
                        SDL_Rect rect = {j * 16, i * 16, 16, 16};
                        SDL_Rect rect_img = {0,0, 16, 16};
                        SDL_RenderCopy(renderer, texture, &rect_img, &rect);
                    }
                    else if(tab[i][j] == '1')
                    {
                        SDL_Rect rect = {j * 16, i * 16, 16, 16};
                        SDL_Rect rect_img = {16,0, 16, 16};
                        SDL_RenderCopy(renderer, texture, &rect_img, &rect);
                    }
                    else if(tab[i][j] == '2')
                    {
                        SDL_Rect rect = {j * 16, i * 16, 16, 16};
                        SDL_Rect rect_img = {32,0, 16, 16};
                        SDL_RenderCopy(renderer, texture, &rect_img, &rect);
                    }
                    else if(tab[i][j] == '3')
                    {
                        SDL_Rect rect = {j * 16, i * 16, 16, 16};
                        SDL_Rect rect_img = {48,0, 16, 16};
                        SDL_RenderCopy(renderer, texture, &rect_img, &rect);
                    }
                    
                    j++;
                }

                i++;
            }
            
            SDL_RenderPresent(renderer);
            
        }
    

    for (i = 0; i < lines; i++) 
    {
        free(tab[i]);
    }

    free(tab);


    while (list != NULL) 
    {
        snake *next = list->next;
        free(list);
        list = next;
    }   
    
    free(file_content);
    
    SDL_Event e;
    while (SDL_PollEvent(&e)) 
    {
        if (e.type == SDL_QUIT) 
        {
            return 0; // Quitter le programme si l'utilisateur ferme la fenêtre
        }
    }
    
}