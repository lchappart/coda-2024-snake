#include "snake.h"

// Update the declaration of wincondition
void eat_fruit(snake **list, fruit *fruit, char **tab)
{
    snake *first = *list;
    if (first->pos_x == fruit->pos_x && first->pos_y == fruit->pos_y)
    {

    add_to_end(list);
    pos_fruit(tab, fruit);
    }
    return;

}
int wincondition(snake **list)
{
    snake *first = *list;
    snake *current = *list;

    // Vérifier si le serpent touche les bords
    if (first->pos_x == 0 || first->pos_x == 39 || first->pos_y == 0 || first->pos_y == 19)
    {
        printf("Vous avez perdu !\n");
        return 0;
    }
    int length = 0;
    current = *list;
    while (current != NULL)
    {
        length++;
        current = current->next;
    }

    if (length >= 684)
    {
        printf("Vous avez gagné !\n");
        return 2; // Retourner 2 pour indiquer la victoire
    }

    while (current != NULL)
    {
        snake *suiv = current->next; // Réinitialiser suiv pour chaque itération de current
        while (suiv != NULL)
        {
            if (first->pos_x == suiv->pos_x && first->pos_y == suiv->pos_y)
            {
                printf("Vous vous êtes mordu la queue !\n");
                return 0;
            }
            suiv = suiv->next;
        }
        current = current->next;
    }

    return 1; // Retourner 1 si aucune condition de perte n'est remplie
}

snake *create_list()
{
    snake *head = malloc(sizeof(snake));
    head->pos_x = 5;
    head->pos_y = 5;
    head->direction = 0;
    head->next = NULL;
    return head;
}

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

void move(snake **list, int direction)
{
    snake *temp = *list;
    int prev_x = temp->pos_x;
    int prev_y = temp->pos_y;
    int prev_direction = temp->direction;

    switch (direction)
    {
        case 0:
            temp->pos_x += 1;
            break;
        case 1:
            temp->pos_x -= 1;
            break;
        case 2:
            temp->pos_y -= 1;
            break;
        case 3:
            temp->pos_y += 1;
            break;
    }

    temp = temp->next;
    while (temp != NULL)
    {
        int temp_x = temp->pos_x;
        int temp_y = temp->pos_y;
        int temp_direction = temp->direction;

        temp->pos_x = prev_x;
        temp->pos_y = prev_y;
        temp->direction = prev_direction;

        prev_x = temp_x;
        prev_y = temp_y;
        prev_direction = temp_direction;

        temp = temp->next;
    }
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

fruit *create_list_fruit()
{
    srand(time(NULL));
    fruit *fruit = malloc(sizeof(fruit));
    fruit->pos_x = rand() % 38 + 1;
    fruit->pos_y = rand() % 18 + 1;
    return fruit;
}

void pos_fruit(char **tab, fruit *list)
{
    fruit *temp = list;
    temp->pos_x = rand() % 38 + 1;
    temp->pos_y = rand() % 18 + 1;
    int rand = 0;
    if(rand != 1)
    {
        for (int i = 1; i < 19; i++)
        {
            for (int j = 1; j < 39; j++)
            {
                if(tab[i][j] == '1')
                {
                    continue;
                }
                else if(tab[i][j] == '0')
                {
                    continue;
                }
                else if(tab[i][j] = ' ')
                {
                    tab[temp->pos_y][temp->pos_x] = '2';
                    rand = 1;
                    break;
                }
            }
        }
    }
}

void pos_bonus(char **tab, fruit *list)
{
    fruit *temp = list;
    temp->pos_bonus_x = rand() % 38 + 1;
    temp->pos_bonus_y = rand() % 18 + 1;
    int rand = 0;
    if(rand != 1)
    {
        for (int i = 1; i < 19; i++)
        {
            for (int j = 1; j < 39; j++)
            {
                if(tab[i][j] == '1')
                {
                    continue;
                }
                else if(tab[i][j] == '0')
                {
                    continue;
                }
                else if(tab[i][j] = '2')
                {
                    continue;
                }
                else if(tab[i][j] = ' ')
                {
                    tab[temp->pos_bonus_y][temp->pos_bonus_x] = '3';
                    rand = 1;
                    break;
                }
            }
        }
    }
}
void eat_bonus(snake **list, fruit *fruit, char **tab, int *del)
{
    snake *first = *list;
    if (first->pos_x == fruit->pos_bonus_x && first->pos_y == fruit->pos_bonus_y)
    {
        *del = *del - 50;
        add_to_end(list);
        pos_bonus(tab, fruit);
    }
    return;

}