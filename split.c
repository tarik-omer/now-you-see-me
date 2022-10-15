// Copyright 2021 - 2022 Omer Tarik Ilhan 314CA
#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
#include "dll_base.h"
#include "errors.h"
#include "delete_stuff.h"
#include <string.h>

void split_decks(doubly_linked_list_t* deck_list)
{
    int index, split_index;
    scanf("%d %d", &index, &split_index);
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
    dll_node_t* deck_node = dll_get_nth_node(deck_list, index);
    doubly_linked_list_t* deck = (doubly_linked_list_t*)(deck_node->data);

    // validate the split index
    if (split_index < 0 || split_index >= deck->size) {
        CARD_INDEX_OUT_OF_BOUNDS(index);
        return;
    } else if (split_index == 0 || split_index == deck->size) {
        // case: one of the resulting decks would be empty
        // becase of the split index
        printf("The deck %d was successfully split by index %d.\n",
               index, split_index);
        return;
    }

    // get the head of the split-to-be list
    dll_node_t* card_node = deck->head;
    // create 2 lists in which to break the initial list
    doubly_linked_list_t* deck_A = dll_create(sizeof(card_t));
    doubly_linked_list_t* deck_B = dll_create(sizeof(card_t));

    // add cards into the first deck
    for (int i = 0; i < split_index; i++) {
        card_t* card = (card_t*)(card_node->data);
        dll_add_nth_node(deck_A, deck_A->size, card);
        card_node = card_node->next;
    }

    // add cards into the second deck
    for (int i = split_index; i < deck->size; i++) {
        card_t* card = (card_t*)(card_node->data);
        dll_add_nth_node(deck_B, deck_B->size, card);
        card_node = card_node->next;
    }

    // add the split lists into the deck list and remove the initial one
    // also check for case: one of the resulting decks would be empty
    // becase of the deck size
    if (deck_A->size > 0)
        dll_add_nth_node(deck_list, index, deck_A);
    else
        dll_free(&deck_A);

    if (deck_B->size > 0)
        dll_add_nth_node(deck_list, index + 1, deck_B);
    else
        dll_free(&deck_A);
    remove_deck(&deck_list, index + 2);
    if (deck_A->size)
        free(deck_A);
    if (deck_B->size)
        free(deck_B);
    printf("The deck %d was successfully split by index %d.\n",
           index, split_index);
}
