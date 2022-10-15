// Copyright 2021 - 2022 Omer Tarik Ilhan 314CA
#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
#include "errors.h"
#include "dll_base.h"
#include "show.h"
#include <string.h>

// remove a deck whose index is given as a parameter
void remove_deck(doubly_linked_list_t** pp_deck_list, int index)
{
        // get the deck's node
        doubly_linked_list_t* deck_list = *pp_deck_list;
        dll_node_t* deck_node = dll_remove_nth_node(deck_list, index);
        // free the list inside that node and then the node itself
        doubly_linked_list_t* deck = (doubly_linked_list_t*)deck_node->data;
        dll_free(&deck);
        free(deck_node);
}

void del_deck(doubly_linked_list_t** pp_deck_list)
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

    doubly_linked_list_t* deck_list = *pp_deck_list;
    // case: invalid deck index
    if (index < 0 || index >= deck_list->size) {
        DECK_INDEX_OUT_OF_BOUNDS();
        return;
    }
    // remove the deck
    remove_deck(pp_deck_list, index);

    printf("The deck %d was successfully deleted.\n", index);
}

void del_card(doubly_linked_list_t** pp_deck_list)
{
    int index, card_index;
    scanf("%d %d", &index, &card_index);
    // validate number of arguments
    char trash[MAX_STR_S];
    fgets(trash, MAX_STR_S, stdin);
    if (strcmp(trash, "\n")) {
        INVALID_COMMAND();
        return;
    }

    doubly_linked_list_t* deck_list = *pp_deck_list;
    // validate deck index
    if (index < 0 || index >= deck_list->size) {
        DECK_INDEX_OUT_OF_BOUNDS();
        return;
    }

    dll_node_t* deck_node = dll_get_nth_node(deck_list, index);
    doubly_linked_list_t* deck = (doubly_linked_list_t*)(deck_node->data);
    // validate card index
    if (card_index < 0 || card_index >= deck->size) {
        CARD_INDEX_OUT_OF_BOUNDS(index);
        return;
    }
    // remove the card
    dll_node_t* card_node = dll_remove_nth_node(deck, card_index);
    free(card_node->data);
    free(card_node);
    // if the deck is empty, remove it
    if (deck->size == 0) {
        remove_deck(pp_deck_list, index);
    }

    printf("The card was successfully deleted from deck %d.\n", index);
}
