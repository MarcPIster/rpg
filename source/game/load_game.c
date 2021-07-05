/*
** EPITECH PROJECT, 2021
** load_game.c
** File description:
** .
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "../../include/my_rpg.h"

// In this code the char **args is for specifying paths to ressources
// such as assets
//
// The index for each specific path are defined in the header file

// The paths to every single tile needs to be specified in a file
// With ONE path to ONE tile on ONE line
sfTexture **load_tileset(char **args)
{
    char *path = args[TILESET_PATH];
    char *buffer = read_file_rpg(path);


    if (!buffer) {
        my_putstr("unable to create a buffer");
        exit(84);
    }
    char **tile_paths = my_str_to_word_array(buffer, '\n');
    int n_tiles;
    sfTexture **output = NULL;

    for (n_tiles = 0; tile_paths[n_tiles]; n_tiles++);
    output = malloc(sizeof(sfTexture *) * n_tiles);
    for (int i = 0; tile_paths[i]; i++)
        output[i] = sfTexture_createFromFile(tile_paths[i], NULL);
    return output;
}

game *load_game(char **args, screen_t *screen)
{
    game *output = malloc(sizeof(game));

    output->render = screen->window;

    output->tileset = load_tileset(args);
    output->tile_sprites = NULL;

    if (!output->render) {
        my_putstr("render not created\n");
        exit(84);
    }
        if (!output->tileset) {
        my_putstr("tileset not created\n");
        exit(84);
    }

    return output;
}