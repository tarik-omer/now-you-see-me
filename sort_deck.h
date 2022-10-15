// Copyright 2021 - 2022 Omer Tarik Ilhan 314CA
#include "structures.h"

#ifndef SORT_DECK_H_
#define SORT_DECK_H_

void sort_deck(doubly_linked_list_t* deck_list);
void swap(card_t* ptr1, card_t* ptr2);
int check_color(card_t* card_1, card_t* card_2);

#endif  // SORT_DECK_H_
