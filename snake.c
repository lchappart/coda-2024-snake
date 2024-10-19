#include "snake.h"

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


int wincondition(snake **list)
{
    snake *first = *list;
    snake *current = *list;
    int length = 0;

    
    if (first->pos_x == 0 || first->pos_x == 39 || first->pos_y == 0 || first->pos_y == 19)
    {
        printf("Vous avez perdu !\n");
        return 0;
    }
    
    current = *list;
    while (current != NULL)
    {
        length++;
        current = current->next;
    }

    if (length >= 684)
    {
        printf("Vous avez gagné !\n");
        return 2; 
    }

    while (current != NULL)
    {
        snake *suiv = current->next;
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

    return 1;
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