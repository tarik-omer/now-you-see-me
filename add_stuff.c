// Copyright 2021 - 2022 Omer Tarik Ilhan 314CA
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"
#include "errors.h"
#include "dll_base.h"
#include "show.h"
#include <ctype.h>
#include <string.h>

// function that checks whether a string is a number
int isNumber(char num[])
{
    for (int i = 0; num[i] != '\0'; i++)
    {
        if (isdigit(num[i]) == 0)
              return 0;
    }
    return 1;
}

// function that sets a card (structure) and validates given data
int set_card(card_t* card, char symbol[MAX_STR_S], char value_s[MAX_STR_S])
{
    int value;
    // setting a value between 1 and 14
    if (isNumber(value_s)) {
        value = atoi(value_s);
    } else {
        return 1;
    }

    if (value >= 1 && value <= 14)
        card->value = value;
    else
        return 1;
    // setting the color integer according to the legend
    // (see card_t definition)
    if (!strcmp(symbol, "HEART"))
        card->color = HEART;
    else if (!strcmp(symbol, "SPADE"))
        card->color = SPADE;
    else if (!strcmp(symbol, "CLUB"))
        card->color = CLUB;
    else if (!strcmp(symbol, "DIAMOND"))
        card->color = DIAMOND;
    else
        return 1;

    return 0;
}

void add_card(doubly_linked_list_t* deck, int* i)
{
    char symbol[MAX_STR_S], value_s[MAX_STR_S];

    scanf("%s %s", value_s, symbol);
    // validate number of arguments
    char trash[MAX_STR_S];
    fgets(trash, MAX_STR_S , stdin);
    if (strcmp(trash, "\n")) {
        INVALID_CARD();
        (*i)--;
        return;
    }

    // set the card and verify the value and symbol
    card_t* card = malloc(sizeof(card_t));
    int verify = set_card(card, symbol, value_s);
    // insert card into deck if it is correct, otherwise move on
    if (verify == 1) {
        INVALID_CARD();
        free(card);
        (*i)--;
        return;
    }
    dll_add_nth_node(deck, deck->size, card);
    free(card);
}

void add_deck(doubly_linked_list_t* deck_list)
{
    int len;
    scanf("%d", &len);
    // validate number of arguments
    char trash[MAX_STR_S];
    fgets(trash, MAX_STR_S , stdin);
    if (strcmp(trash, "\n") || len == 0) {
        INVALID_COMMAND();
        return;
    }

    // create a deck that is to be filled with cards
    doubly_linked_list_t* deck = dll_create(sizeof(card_t*));

    // create each individual card
    for (int i = 0; i < len; i++) {
        add_card(deck, &i);
    }
    // add the deck to the deck list
    dll_add_nth_node(deck_list, deck_list->size, deck);
    printf("The deck was successfully created with %d cards.\n", deck->size);
    free(deck);
}

void add_more_cards(doubly_linked_list_t* deck_list)
{
    int index, card_num;
    scanf("%d %d", &index, &card_num);
    // validate number of arguments
    char trash[MAX_STR_S];
    fgets(trash, MAX_STR_S, stdin);
    if (strcmp(trash, "\n")) {
        INVALID_COMMAND();
        return;
    }
    // validate deck index
    if (index < 0 || index >= deck_list->size) {
        DECK_INDEX_OUT_OF_BOUNDS();
        return;
    }
    // get the deck
    dll_node_t* deck_node = dll_get_nth_node(deck_list, index);
    doubly_linked_list_t* deck = (doubly_linked_list_t*)(deck_node->data);
    // add cards to the deck
    for (int i = 0; i < card_num; i++)
        add_card(deck, &i);

    printf("The cards were successfully added to deck %d.\n", index);
}
