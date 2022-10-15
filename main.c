// Copyright 2021 - 2022 Omer Tarik Ilhan 314CA
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"
#include "add_stuff.h"
#include "dll_base.h"
#include "show.h"
#include "deck_info.h"
#include "delete_stuff.h"
#include "exit.h"
#include "shuffle.h"
#include "reverse.h"
#include "merge.h"
#include "split.h"
#include "sort_deck.h"
#include "errors.h"

int main(void)
{
    doubly_linked_list_t* deck_list = dll_create(sizeof(doubly_linked_list_t));
    char command[MAX_STR_S];
    // loop in which commands are read
    while (1) {
        scanf("%s", command);

        if (!strcmp(command, "ADD_DECK")) {
            add_deck(deck_list);
        } else if (!strcmp(command, "DEL_DECK")) {
            del_deck(&deck_list);
        } else if (!strcmp(command, "DEL_CARD")) {
            del_card(&deck_list);
        } else if (!strcmp(command, "ADD_CARDS")) {
            add_more_cards(deck_list);
        } else if (!strcmp(command, "DECK_NUMBER")) {
            deck_num(deck_list);
        } else if (!strcmp(command, "DECK_LEN")) {
            deck_len(deck_list);
        } else if (!strcmp(command, "SHUFFLE_DECK")) {
            shuffle_deck(deck_list);
        } else if (!strcmp(command, "MERGE_DECKS")) {
            merge_decks(deck_list);
        } else if (!strcmp(command, "SPLIT_DECK")) {
            split_decks(deck_list);
        } else if (!strcmp(command, "REVERSE_DECK")) {
            reverse_deck(deck_list);
        } else if (!strcmp(command, "SHOW_DECK")) {
            show_deck(deck_list);
        } else if (!strcmp(command, "SHOW_ALL")) {
            show_all(deck_list);
        } else if (!strcmp(command, "EXIT")) {
            shut_it_down(&deck_list);
            break;
        } else if (!strcmp(command, "SORT_DECK")) {
            sort_deck(deck_list);
        } else {
            // get the rest of the line if the command does not exist
            char trash[MAX_STR_S];
            fgets(trash, MAX_STR_S, stdin);
            INVALID_COMMAND();
        }
    }

    return 0;
}
