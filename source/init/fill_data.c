/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** fill data
*/

#include "../../include/my_rpg.h"

void free_parsed_csv(csv *parsed_csv)
{
    for (int i = 0; parsed_csv->labels[i]; i++)
        free(parsed_csv->labels[i]);
    for (int i = 0; parsed_csv->data[i]; i++)
        free(parsed_csv->data[i]);
    free(parsed_csv->labels);
    free(parsed_csv->data);
}

int *my_word_array_to_int_array(char **data)
{
    int *data_as_int = NULL;
    int a = 0;

    for (; data[a] != NULL; a++);
    data_as_int = malloc(sizeof(int) * a);
    for (int i = 0; i < a; i++) {
        data_as_int[i] = my_getnbr(data[i]);
    }
    free_char_table(data);
    return data_as_int;
}

void load_monster2(csv *parsed_csv, mob_data *mob, int i, int is_boss)
{
    mob->battle = sfTexture_createFromFile(parsed_csv->data[i][4], NULL);
    mob->dying = sfTexture_createFromFile(parsed_csv->data[i][3], NULL);
    mob->walking = sfTexture_createFromFile(parsed_csv->data[i][1], NULL);
    mob->portrait = sfTexture_createFromFile(parsed_csv->data[i][2], NULL);
    mob->animnums.y = my_getnbr(parsed_csv->data[i][7]);
    mob->animnums.x = my_getnbr(parsed_csv->data[i][8]) - 1;
    mob->position.x = my_getnbr(parsed_csv->data[i][9]);
    mob->position.y = my_getnbr(parsed_csv->data[i][10]);
    mob->is_alive = my_getnbr(parsed_csv->data[i][11]);
    mob->has_spawned = my_getnbr(parsed_csv->data[i][12]);
    mob->anim_clock = sfClock_create();
    mob->out_sprite = sfSprite_create();
    mob->movespeed = my_getnbr(parsed_csv->data[i][13]);
    mob->aggrorange = my_getnbr(parsed_csv->data[i][14]);
    mob->infight = 0;
    mob->minspawnlevel  = my_getnbr(parsed_csv->data[i][17]);
    mob->loot_table = my_word_array_to_int_array(my_str_to_word_array\
    (parsed_csv->data[i][15], ';'));
}

void load_monster3(csv *parsed_csv, mob_data *mob, int i)
{
    int *mob_stats = my_word_array_to_int_array(my_str_to_word_array\
    (parsed_csv->data[i][16], ';'));
    mob->hp = mob_stats[0];
    mob->atk = mob_stats[1];
    mob->def = mob_stats[2];
    mob->magic = mob_stats[3];
    mob->speed = mob_stats[4];
}

mob_data *parse_monsters(char *monster_csv_path)
{
    csv *parsed_csv = parse_csv(monster_csv_path);
    mob_data *monster = malloc(sizeof(mob_data) * (parsed_csv->n_rows + 1));

    for (int i = 0; i < parsed_csv->n_rows; i++) {
        monster[i].name = parsed_csv->data[i][0];
        monster[i].anim_rect.top = 0;
        monster[i].anim_rect.left = 0;
        monster[i].anim_rect.width = my_getnbr(parsed_csv->data[i][6]);
        monster[i].anim_rect.height = my_getnbr(parsed_csv->data[i][5]);
        monster[i].origin.x = monster[i].anim_rect.width / 2;
        monster[i].origin.y = monster[i].anim_rect.height / 2;
        monster[i].aggro = 0;                
        monster[i].unit_amount = parsed_csv->n_rows;
        
        load_monster2(parsed_csv, &monster[i], i, 0);
        load_monster3(parsed_csv, &monster[i], i);
        sfSprite_setOrigin(monster[i].out_sprite, monster[i].origin);
        sfSprite_setTextureRect(monster[i].out_sprite, monster[i].anim_rect);
        sfSprite_setTexture(monster[i].out_sprite, monster[i].walking, 0);
    }
    free_parsed_csv(parsed_csv);
    return monster;
}