/*
** EPITECH PROJECT, 2021
** B-MUL-200-BER-2-1-myrpg-gylian.karsch
** File description:
** init_itemlist
*/

#include "../include/my_rpg.h"

item_list *init_itemslist(char *itemlist_csv_path)
{
    csv *parsed_csv = parse_csv(itemlist_csv_path);
    item_list *items = malloc(sizeof(item_list) * (parsed_csv->n_rows + 1));

    for (int i = 0; i < parsed_csv->n_rows; i++) {
        items[i].item_name = parsed_csv->data[i][0];
        items[i].item_index = i;
        items[i].use_hp = my_getnbr(parsed_csv->data[i][1]);
        items[i].use_hpmax = my_getnbr(parsed_csv->data[i][2]);
        items[i].use_atk = my_getnbr(parsed_csv->data[i][3]);
        items[i].use_def = my_getnbr(parsed_csv->data[i][4]);
        items[i].use_speed = my_getnbr(parsed_csv->data[i][5]);
        items[i].use_mvspeed = my_getnbr(parsed_csv->data[i][6]);
        items[i].use_mag = my_getnbr(parsed_csv->data[i][7]);
        items[i].equipable = my_getnbr(parsed_csv->data[i][8]);
        items[i].equiped = my_getnbr(parsed_csv->data[i][9]);
    }
    return items;
}

item_list *init_inventory(void)
{
    item_list *inventory = malloc(sizeof(item_list) * 8);

    for (int i = 0; i < 8; i++) {
        inventory[i].item_name = "-EMPTY-";
        inventory[i].item_index = -1;
        inventory[i].use_hp = 0;
        inventory[i].use_hpmax = 0;
        inventory[i].use_atk = 0;
        inventory[i].use_def = 0;
        inventory[i].use_speed = 0;
        inventory[i].use_mvspeed = 0;
        inventory[i].use_mag = 0;
        inventory[i].equipable = 0;
        inventory[i].equiped = 0;
    }
    return inventory;
}