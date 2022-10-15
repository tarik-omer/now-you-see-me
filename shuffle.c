// Copyright 2021 - 2022 Omer Tarik Ilhan 314CA
#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
#include "errors.h"
#include "dll_base.h"
#include <string.h>

void shuffle_deck(doubly_linked_list_t* deck_list)
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

    // validate index
    if (index < 0 || index >= deck_list->size) {
        DECK_INDEX_OUT_OF_BOUNDS();
        return;
    }

    // get the deck
    dll_node_t* deck_node = dll_get_nth_node(deck_list, index);
    doubly_linked_list_t* deck = (doubly_linked_list_t*)(deck_node->data);
    // get the point where to "cut" the deck
    int half = deck->size / 2;
    // since we use a circular doubly linked list,
    // we can set the list head to the node that we cut to
    deck->head = dll_get_nth_node(deck, half);
    printf("The deck %d was successfully shuffled.\n", index);
}
