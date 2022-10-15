// Copyright 2021 - 2022 Omer Tarik Ilhan 314CA
#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
#include "dll_base.h"
#include "delete_stuff.h"

void shut_it_down(doubly_linked_list_t** pp_deck_list)
{
    doubly_linked_list_t* deck_list = *pp_deck_list;
    // delete decks until its size reaches 0
    // there is no "i++" in the for because
    // with each removal of a deck, the deck_list->size
    //  decreases by 1, so it is an equivalent to i++
    for (int i = 0; i < deck_list->size; ) {
        // remove each deck
        remove_deck(pp_deck_list, 0);
    }
    // free the deck list
    dll_free(pp_deck_list);
}
