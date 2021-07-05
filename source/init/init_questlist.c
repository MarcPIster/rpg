/*
** EPITECH PROJECT, 2021
** B-MUL-200-BER-2-1-myrpg-gylian.karsch
** File description:
** init_questlist
*/

#include "../include/my_rpg.h"

quest_list *init_questlist(void)
{
    quest_list *questlist = malloc(sizeof(quest_list) * 8);

    for (int i = 0; i < 8; i++) {
        questlist[i].quest_name = "-EMPTY-";
        questlist[i].quest_index = -1;
        questlist[i].completed = 0;
        questlist[i].item_reward_index = -1;
        questlist[i].mob_to_kill_index = -1;
        questlist[i].exp_reward = 0;
        questlist[i].atk_reward = 0;
        questlist[i].def_reward = 0;
        questlist[i].magic_reward = 0;
        questlist[i].quest_text = NULL;
        questlist[i].item_to_have_index = -1;
    }
    return questlist;
}

quest_list *init_all_quests(char *quest_csv_path)
{
    csv *parsed_csv = parse_csv(quest_csv_path);
    quest_list *book = malloc(sizeof(quest_list) * (parsed_csv->n_rows + 1));


    for (int i = 0; i < parsed_csv->n_rows; i++) {
        book[i].quest_name = parsed_csv->data[i][0];
        book[i].quest_text = parsed_csv->data[i][1];        
        book[i].quest_index = i; 
        book[i].completed = 0;
        book[i].item_reward_index = my_getnbr(parsed_csv->data[i][2]);
        book[i].mob_to_kill_index = my_getnbr(parsed_csv->data[i][3]);
        book[i].exp_reward = my_getnbr(parsed_csv->data[i][4]);
        book[i].atk_reward = my_getnbr(parsed_csv->data[i][5]);
        book[i].magic_reward = my_getnbr(parsed_csv->data[i][6]);
        book[i].def_reward = my_getnbr(parsed_csv->data[i][7]);
        book[i].item_to_have_index = my_getnbr(parsed_csv->data[i][8]);
    }

    return book;

}
