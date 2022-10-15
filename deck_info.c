// Copyright 2021 - 2022 Omer Tarik Ilhan 314CA
#include <stdio.h>
#include "structures.h"
#include "errors.h"
#include "dll_base.h"
#include <string.h>

// function that prints number of stored decks
void deck_num(doubly_linked_list_t* deck_list)
{
    // validate number of arguments
    char trash[MAX_STR_S];
    fgets(trash, MAX_STR_S, stdin);
    if (strcmp(trash, "\n")) {
        INVALID_COMMAND();
        return;
    }

    printf("The number of decks is %d.\n", deck_list->size);
}

// function that prints the length of a deck whose index is read from stdin
void deck_len(doubly_linked_list_t* deck_list)
{
    int index;
    scanf("%d", &index);
    // validate number of arguments
    char trash[MAX_STR_S];
    fgets(trash, MAX_STR_S, stdin);
    if (strcmp(trash, "\n")) {
        INVALID_COMMAND();
        return;
    }
    // validate the index
    if (index < 0 || index >= deck_list->size) {
        DECK_INDEX_OUT_OF_BOUNDS();
        return;
    }
    // get the deck
    doubly_linked_list_t* deck = (doubly_linked_list_t*)((dll_node_t*)
                                (dll_get_nth_node(deck_list, index)))->data;
    printf("The length of deck %d is %d.\n", index, deck->size);
}
