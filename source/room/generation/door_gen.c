/*
** EPITECH PROJECT, 2020
** my_isneg
** File description:
** Day03 Task04
*/

#include "../../../include/my_rpg.h"


int get_random_num_gen (int min, int max)
{
    int my_random = 0;

    max += 1;
    my_random = random() % (max - min) + min;
    return my_random;
}

int *door_cords_int(int *max, int side, int *coords)
{
    switch (side)
    {
    case 0:
        (coords[0]) = get_random_num_gen(1, max[0] - 1);
        (coords[1]) = 0;
        (coords[2]) = side;        
        return coords;
    case 1:
        (coords[0]) = max[0];
        (coords[1]) = get_random_num_gen(1, max[1] - 1);
        (coords[2]) = side;
        return coords;
    case 2:
        (coords[0]) = get_random_num_gen(1, max[0] - 1);
        (coords[1]) = max[1];
        (coords[2]) = side; 
        return coords;  
    case 3:
        (coords[0]) = 0;
        (coords[1]) = get_random_num_gen(1, max[1] - 1);
        (coords[2]) = side;
        return coords;
    default:
        (coords[0]) = -1;
        (coords[1]) = -1;
        (coords[2]) = -1;
        return coords;
    }
    return coords;
}

//return an array
//coords[0][1] = x position of door 1
//coords[0][2] = y position of door 1
//coords[0][3] = description where the door is; 0 == top 1== right, 2 == bottom, 3 == left 
//ndoors = max 3
int **door_gen(int height, int width, int n_doors)
{
    srandom(time(0));
    int *max = malloc(sizeof(int)*2);
    max[0] = width;
    max[1] = height; 
    int side = 0;
    int index = 0;
    int count = 0;
    int **coords = malloc(sizeof(int*) * (n_doors+1));
    int *check = malloc(sizeof(int)* (n_doors + 1));
    int i = 0;

    for (int x = 0; x < n_doors; x++)
        check[x] = -1;
    check[n_doors] = NULL;

    for (; i < n_doors; i++) {
        side = get_random_num_gen(0, 2);
        for (int l = 0; l < n_doors; l++) {
            while (check[l] == side) {
                side = get_random_num_gen(0, 2);
                l = 0;
            }
        }
        check[i] = side;
        coords[i] = malloc(sizeof(int) * 3);
        coords[i] = door_cords_int(max, side, coords[i]);
    }
    coords[i] = NULL;
    for (int x = 0; coords[x] != NULL; x++)
        printf("Door: %i, x == %i, y == %i     side == %i\n", x, coords[x][0], coords[x][1], coords[x][2]);
    return coords;
}