// Copyright 2021 - 2022 Omer Tarik Ilhan 314CA
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dll_base.h"
#include "structures.h"
#include "errors.h"

// function that swaps the data of 2 cards
void swap(card_t* ptr1, card_t* ptr2)
{
    card_t aux = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = aux;
}

// function that checks whether the order of 2 card symbols is correct
int check_color(card_t* card_1, card_t* card_2)
{
    if (card_1->color > card_2->color)
        return 1;
    return 0;
}

void sort_deck(doubly_linked_list_t* deck_list)
{
    int index;
    scanf("%d", &index);
    // validate number of arguments
    char trash[50];
    fgets(trash, 50 , stdin);
    if (strcmp(trash, "\n")) {
        INVALID_COMMAND();
        return;
    }
    // validate deck index
    if (index < 0 || index >= deck_list->size) {
        DECK_INDEX_OUT_OF_BOUNDS();
        return;
    }
    // get the node
    dll_node_t* deck_node = dll_get_nth_node(deck_list, index);
    doubly_linked_list_t* deck = (doubly_linked_list_t*)(deck_node->data);

    int is_sorted = 0;
    while (!is_sorted) {
        // iterate until deck is sorted
        is_sorted = 1;
        dll_node_t* card_node = deck->head;
        for (int i = 0; i < deck->size - 1; i++) {
            card_t* card = (card_t*)card_node->data;
            card_t* next_card = (card_t*)card_node->next->data;
            // first check values
            if (card->value > next_card->value) {
                swap(card, next_card);
                is_sorted = 0;
            // then, check colors
            } else if (card->value == next_card->value) {
                int check = check_color(card, next_card);
                if (check) {
                    swap(card, next_card);
                    is_sorted = 0;
                }
            }
            card_node = card_node->next;
        }
    }
    printf("The deck %d was successfully sorted.\n", index);
}
