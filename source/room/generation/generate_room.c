/*
** EPITECH PROJECT, 2020
** my_isneg
** File description:
** Day03 Task04
*/

#include "../../../include/my_rpg.h"

int get_random_num (int min, int max)
{
    int my_random = 0;

    max += 1;
    my_random = random() % (max - min) + min;
    return my_random;
}

int **create_room(int length, int height, int doors)
{
    int **roomarray = malloc(sizeof(int*) * (height + 1));
    int **door;
    roomarray[height] = NULL;

    printf("length = %i\n", length);
    for (int x = 0; x < height; x++) {
        roomarray[x] = malloc(sizeof(int) * (length + 1));
        for (int y = 0; y < length; y++) {
             roomarray[x][y] = 0;
        }
        roomarray[x][0] = 1;
        roomarray[x][length - 1] = 1;
        roomarray[x][length] = NULL;
    }
    for (int x = 0; x < length; x++) {
        roomarray[0][x] = 1;
        roomarray[height - 1][x] = 1;
    }
    roomarray[0][13] = 2;
    roomarray[7][0] = 2;
    roomarray[height-1][13] = 2;
    roomarray[7][length-1] = 2;
    return roomarray;
}

void random_door_select(int lenght, int height, room *myroom)
{
    int rand_nb = my_random(2);
    int check = 0;

    for (int i = 0; i < height; i++) {
        for (int x = 0; x < lenght; x++) {
            if (myroom->tiling[i][x] == 2) {
                check += 1;
            }
            if (myroom->tiling[i][x] == 2 && ((check == rand_nb && rand_nb != 2) || check == 4)) {
                myroom->active_door.x = x * 47;
                myroom->active_door.y = i * 47;
                printf("Check = %i && Rand = %i\n", check, rand_nb);
                return;
            }
        }
    }
}

room *create_room_struct(int length, int height, doorways *next)
{
    room *myroom = malloc(sizeof(room));

    myroom->tiling = create_room(length, height, 3);
    random_door_select(length, height, myroom);
    return myroom;
}

doorways create_doorway_struct(int howmany, int max, int min)
{
    doorways mydoorway;
    mydoorway.shape = create_room(5, 10, 3);
    mydoorway.next_room = NULL;
    mydoorway.arrival_doorway = 0;
    return mydoorway;
}