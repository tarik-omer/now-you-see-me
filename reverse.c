// Copyright 2021 - 2022 Omer Tarik Ilhan 314CA
#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
#include "errors.h"
#include "delete_stuff.h"
#include "dll_base.h"
#include <string.h>

void reverse_deck(doubly_linked_list_t* deck_list)
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
    // reverse the node links (prev to next)
    dll_node_t* node = deck->head;
    for (int i = 0; i < deck->size; i++) {
        node->prev = node->next;
        node = node->next;
    }
    // reverse the node links (next to prev)
    node = deck->head;
    for (int i = 0; i < deck->size; i++) {
        node->prev->next = node;
        node = node->prev;
    }
    // set the new deck head
    deck->head = deck->head->next;

    printf("The deck %d was successfully reversed.\n", index);
}
