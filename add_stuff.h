// Copyright 2021 - 2022 Omer Tarik Ilhan 314CA
#include "structures.h"

#ifndef ADD_STUFF_H_
#define ADD_STUFF_H_

int isNumber(char num[]);
void add_card(doubly_linked_list_t* deck, int* i);
int set_card(card_t* card, char symbol[MAX_STR_S], int value);
void add_deck(doubly_linked_list_t* deck_list);
void add_more_cards(doubly_linked_list_t* deck_list);

#endif  // ADD_STUFF_H_
