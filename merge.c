// Copyright 2021 - 2022 Omer Tarik Ilhan 314CA
#include <stdio.h>
#include <stdlib.h>
#include "add_stuff.h"
#include "delete_stuff.h"
#include "structures.h"
#include "dll_base.h"
#include "errors.h"
#include <string.h>

void merge_decks(doubly_linked_list_t* deck_list)
{
    int index_1, index_2;
    scanf("%d %d", &index_1, &index_2);
    // validate number of arguments
    char trash[MAX_STR_S];
    fgets(trash, MAX_STR_S, stdin);
    if (strcmp(trash, "\n")) {
        INVALID_COMMAND();
        return;
    }

    // validate the indexes
    if (index_1 < 0 || index_2 < 0 ||
        index_1 >= deck_list->size || index_2 >= deck_list->size) {
        DECK_INDEX_OUT_OF_BOUNDS();
        return;
    }
    // get the deck nodes
    dll_node_t* deck_node_1 = dll_get_nth_node(deck_list, index_1);
    dll_node_t* deck_node_2 = dll_get_nth_node(deck_list, index_2);
    // get the decks
    doubly_linked_list_t* deck_1 = (doubly_linked_list_t*)deck_node_1->data;
    doubly_linked_list_t* deck_2 = (doubly_linked_list_t*)deck_node_2->data;
    // get the decks' first cards
    dll_node_t* card_1 = deck_1->head;
    dll_node_t* card_2 = deck_2->head;
    // get the first cards' info
    card_t* data_1 = (card_t*)(card_1->data);
    card_t* data_2 = (card_t*)(card_2->data);

    // create a new deck in which to place the merged decks
    doubly_linked_list_t* deck_merged = dll_create(sizeof(card_t));
    // get the sizes and an index to use to know when to add from which deck
    int size_1 = deck_1->size, size_2 = deck_2->size, i = 0;

    // iterate until both decks are depleted
    while (size_1 != 0 || size_2 != 0) {
        if (size_2 == 0 || (i % 2 == 0 && size_1 > 0)) {
            // even steps or second deck is depleted
            dll_add_nth_node(deck_merged, deck_merged->size, data_1);
            card_1 = card_1->next;
            size_1--;
        } else if (size_1 == 0 || (i % 2 == 1 && size_2 > 0)) {
            // odd steps or first deck is depleted
            dll_add_nth_node(deck_merged, deck_merged->size, data_2);
            card_2 = card_2->next;
            size_2--;
        }
        // update card info variable and increment step
        i++;
        data_1 = (card_t*)(card_1->data);
        data_2 = (card_t*)(card_2->data);
    }

    printf("The deck %d and the deck %d were successfully merged.\n",
           index_1, index_2);
    // when we remove decks, we have to consider that when a deck is removed
    // it affects the index of all the decks after it
    if (index_1 > index_2) {
        int aux = index_1;
        index_1 = index_2;
        index_2 = aux;
    }
    // add the merged deck to the deck list
    // and remove the ones used for the merge
    remove_deck(&deck_list, index_2);
    remove_deck(&deck_list, index_1);
    dll_add_nth_node(deck_list, deck_list->size, deck_merged);
    free(deck_merged);
}
