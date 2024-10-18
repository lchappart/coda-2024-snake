#include "snake.h"




void add_to_end(snake **list)
{
    snake *new_node = malloc(sizeof(snake));
    snake *temp = *list;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    new_node->pos_x = temp->pos_x - 1;
    new_node->pos_y = temp->pos_y;
    new_node->direction = temp->direction;
    new_node->next = NULL;
    temp->next = new_node;
}



// Update the declaration of refresh_map


void refresh_map(char **tab, snake *list, fruit *fruit)
{
    snake *temp = list;

    // Réinitialiser la carte
    for (int i = 1; i < 19; i++)
    {
        for (int j = 1; j < 39; j++)
        {
            tab[i][j] = ' ';
        }
    }

    // Mettre à jour la position du serpent sur la carte
    while (temp != NULL)
    {
        tab[temp->pos_y][temp->pos_x] = '1';
        temp = temp->next;
    }

    // Mettre à jour la position du fruit sur la carte
    if (fruit != NULL)
    {
        tab[fruit->pos_y][fruit->pos_x] = '2';
        tab[fruit->pos_bonus_y][fruit->pos_bonus_x] = '3';
    }
}

char * get_file(FILE * fp)
{
    char * content;
    char buffer[10];

    content = malloc(sizeof(char));
    content[0] = '\0';

    while(fgets(buffer, 10, fp) != NULL)
    {
        content = realloc(content, (strlen(buffer) * sizeof(char)) + strlen(content) * sizeof(char) + 1);
        content = strcat(content, buffer);
    }

    return content;
}

int count_lines(char *str)
{
    int i = 0;
    int lines = 0;

    while(str[i] != '\0')
    {
        if(str[i] == '\n')
        {
            lines++;
        }

        i++;
    }

    return lines;
}

void display_tab(char **tab, int lines)
{
    int i = 0;

    while(i < lines)
    {
        printf("%s\n", tab[i]);
        i++;
    }
}
