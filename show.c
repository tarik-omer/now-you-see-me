// Copyright 2021 - 2022 Omer Tarik Ilhan 314CA
#include "dll_base.h"
#include <stdio.h>
#include "structures.h"
#include "errors.h"
#include <string.h>

// function that prints a given deck
void show_deck_given(doubly_linked_list_t* list)
{
    dll_node_t* it = list->head;
    for (unsigned int i = 0; i < list->size; i++) {
        // the value
        printf("\t%d ", (int)(((card_t*)(it->data))->value));
        // each color for the corresponding integer
        if ((int)(((card_t*)(it->data))->color) == HEART)
            printf("HEART");
        else if ((int)(((card_t*)(it->data))->color) == CLUB)
            printf("CLUB");
        else if ((int)(((card_t*)(it->data))->color) == DIAMOND)
            printf("DIAMOND");
        else if ((int)(((card_t*)(it->data))->color == SPADE))
            printf("SPADE");
        printf("\n");
        it = it->next;
    }
}

// function that prints a deck whose index is read from stdin
void show_deck(doubly_linked_list_t* deck_list)
{
    int i;
    scanf("%d", &i);
    // validate number of arguments
    char trash[MAX_STR_S];
    fgets(trash, MAX_STR_S, stdin);
    if (strcmp(trash, "\n")) {
        INVALID_COMMAND();
        return;
    }

    // validate the index
    if (i < 0 || i >= deck_list->size) {
        DECK_INDEX_OUT_OF_BOUNDS();
        return;
    }

    printf("Deck %d:\n", i);
    // get the deck
    dll_node_t* deck_node = dll_get_nth_node(deck_list, i);
    doubly_linked_list_t* deck = (doubly_linked_list_t*)(deck_node->data);
    // print the deck itself
    show_deck_given(deck);
}

// function that prints all the stored decks
void show_all(doubly_linked_list_t* deck_list)
{
    // validate number of arguments
    char trash[MAX_STR_S];
    fgets(trash, MAX_STR_S, stdin);
    if (strcmp(trash, "\n")) {
        INVALID_COMMAND();
        return;
    }

    dll_node_t* it = deck_list->head;
    for (int i = 0; i < deck_list->size; i++) {
        printf("Deck %d:\n", i);
        doubly_linked_list_t* deck = (doubly_linked_list_t*)it->data;
        show_deck_given(deck);
        it = it->next;
    }
}
