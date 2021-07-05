##
## EPITECH PROJECT, 2021
## my_defender
## File description:
## makefile
##

CFLAGS = -g3 -W -Wall -Wextra -I./include

SRC	=	./source/main.c \
		./source/animation/update_animations.c \
		./source/animation/move_idle_animations.c \
		./source/animation/animate_player_movement.c \
		./source/animation/animate_mob_movement.c \
		./source/destroy/destroy.c \
		./source/destroy/destroy_gameloop.c \
		./source/destroy/destroy_gameloop_two.c\
		./source/game/draw_scenes.c \
		./source/game/gameloop_events.c \
		./source/game/load_game.c \
		./source/game/pause_buttons.c \
		./source/game/pause_events.c \
		./source/game/enter_combat.c \
		./source/game/setting_events.c \
		./source/init/csv_parser.c \
		./source/init/fill_data.c \
		./source/init/read_file.c \
		./source/init/init_fight_scene.c \
		./source/init/init_player.c \
		./source/init/init_help_menu.c \
		./source/init/init_help_menu_two.c \
		./source/init/init_help_menu_three.c \
		./source/init/init_main_buttons.c \
		./source/init/init_main_menu.c \
		./source/init/init_pause.c \
		./source/init/init_pause_two.c \
		./source/init/init_settings.c \
		./source/init/init_settings_two.c \
		./source/init/init_structure_scene.c \
		./source/menu/help_menu_events.c \
		./source/menu/main_menu_events.c \
		./source/mobs/mob_aggro.c \
		./source/movement/move_player.c \
		./source/room/generation/generate_room.c \
		./source/room/runtime/launch_room.c \
		./source/room/runtime/runtime_functions.c \
		./source/tiling/tiling_utilities.c \
		./source/tiling/tiling.c \
		./source/init/init_statmenu.c \
		./source/init/init_statmenu2.c \
		./source/stats_menu/stats_menu.c \
		./source/stats_menu/display_stat_menu.c \
		./source/stats_menu/my_return_number.c \
		./source/init/init_itemlist.c \
		./source/init/init_inventory.c \
		./source/stats_menu/display_inventory.c \
		./source/stats_menu/use_inventory.c \
		./source/stats_menu/use_inventory2.c \
		./source/fightsystem/screen/fight.c \
		./source/fightsystem/screen/stats_generation.c \
		./source/fightsystem/screen/call_buttons.c \
		./source/fightsystem/screen/change_state_button.c \
		./source/fightsystem/screen/intro_scene.c \
		./source/fightsystem/screen/declare_buttons.c \
		./source/fightsystem/screen/button_draw.c \
		./source/fightsystem/screen/declare_text.c \
		./source/fightsystem/screen/init_structures.c \
		./source/fightsystem/screen/fightsystem.c \
		./source/fightsystem/screen/fightingsystem2.c \
		./source/init/init_npcs.c \
		./source/npcs/npc_aggro.c \
		./source/animation/animate_npc_movement.c \
		./source/game/interact_with_npc.c \
		./source/init/init_quest_log.c \
		./source/questlog/quest_log.c \
		./source/init/init_quests.c \
		./source/questlog/display_questlog.c \
		./source/init/init_questlist.c \
		./source/questlog/abandon_quests.c \
		./source/questlog/quests_check.c \
		./source/init/init_fx.c \
		./source/animation/animate_fx.c \
		./source/movement/check_movement.c




NAME	=	my_rpg

OBJ	= $(SRC:.c=.o)

all:	$(NAME) clean

$(NAME):	$(OBJ)
			cd lib/my/ && make
			cd ../..
			gcc -o $(NAME) $(OBJ) -Llib -lmy -l csfml-window -l csfml-graphics -l csfml-system -l csfml-audio -g3 -lpthread -lm

clean:
		cd lib/my && make clean
		cd ../..
		rm -f $(OBJ)
		rm -rf *.dSYM

fclean:	clean
		cd lib/my && make fclean
		cd ../..
		rm -f $(NAME)

re:	all clean