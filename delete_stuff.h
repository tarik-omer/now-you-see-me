// Copyright 2021 - 2022 Omer Tarik Ilhan 314CA
#include "structures.h"

#ifndef DELETE_STUFF_H_
#define DELETE_STUFF_H_

void del_deck(doubly_linked_list_t** pp_deck_list);
void del_card(doubly_linked_list_t** pp_deck_list);
void remove_deck(doubly_linked_list_t** pp_deck_list, int index);

#endif  // DELETE_STUFF_H_
