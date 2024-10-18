#include "snake.h"

fruit *create_list_bonus(char ** tab)
{
    int random = 0;
    srand(time(NULL));
    fruit *fruit = malloc(sizeof(fruit));
    fruit->pos_bonus_x = rand() % 38 + 1;
    fruit->pos_bonus_y = rand() % 18 + 1;
    
    while (random != 1)
    {
                
                if(tab[fruit->pos_bonus_y][fruit->pos_bonus_x] = ' ')
                {
                    tab[fruit->pos_bonus_y][fruit->pos_bonus_x] = '3';
                    random = 1;
                }
    }
    return fruit;
}

/*void pos_bonus(char **tab, fruit *list)
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
}*/



int eat_bonus(snake **list, fruit *fruit, char **tab, int del)
{
    snake *first = *list;
    if (first->pos_x == fruit->pos_bonus_x && first->pos_y == fruit->pos_bonus_y)
    {
        del = del - 80;
        add_to_end(list);
    }
    return del;

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