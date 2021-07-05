/*
** EPITECH PROJECT, 2021
** tiling.c
** File description:
** .
*/

#include "room.h"
#include <time.h>
#include <stdlib.h>


int get_random_num (int min, int max)
{
    int my_random = 0;

    max += 1;
    my_random = random() % (max - min) + min;
    return my_random;
}

int **gen_tiling(int min, int max)
{
    srandom(time(0));
    int length = get_random_num(min, max);
    int height = get_random_num(min, max);
    int **roomarray = malloc(sizeof(int*) * (height + 1));
    roomarray[height] = NULL;

    for (int x = 0; x < height; x++) {
        roomarray[x] = malloc(sizeof(int)* (length + 1));
        for (int y = 0; y < length; y++) {
            roomarray[x][y] = WALL;
        }
        roomarray[x][0] = FLOOR;
        roomarray[x][length - 1] = FLOOR;
        roomarray[x][length] = NULL;
    }
    for (int x = 0; x < length; x++) {
        roomarray[0][x] = FLOOR;
        roomarray[height - 1][x] = FLOOR;
    }
    return roomarray;
}
