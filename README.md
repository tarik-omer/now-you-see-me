# Now you see me - Homework 1

**Name: Omer Tarik Ilhan**

**Group: 314CA**

## Description:

For the implementation of this homework, I used 2 generic list data structures:

* dll_node_t
* doubly_linked_list_t

And 1 specific data structure for the card information storage:

* card_t

Each card has 2 fields:

* value - a numeric value from 1 to 14
* symbol - 1 of 4 symbols: Heart, Spade, Diamond, Club

Also, for ease of use, the card color was stored in an integer
with values from 0 to 3, each corresponding to a specific symbol.

The main source code contains an infinite while loop which reads
from stdin commands until the user inputs the EXIT command.

There are a total of 14 commands available for the user:

    * ADD_DECK <cards_number> - adds a deck of <cards_number> cards read from the stdin; read format: <value> <symbol>

    * ADD_CARDS <deck_index> <cards_number> - adds cards to a deck of index <deck_index>

    * DEL_DECK <deck_index> - deletes a deck of index <deck_index>

    * DEL_CARD <deck_index> <card_index> - deletes a card of index <card_index> from deck <deck_index>

    * DECK_NUMBER - prints to stdin the number of stored decks

    * DECK_LEN <deck_index> - prints to stdin number of stored cards in deck <deck_index>

    * SHUFFLE_DECK <deck_index> - switches first half with second half of deck <deck_index>; also known as "cutting the deck"

    * REVERSE_DECK <deck_index> - reverses storage of cards in deck <deck_index>

    * MERGE_DECKS <deck_index_1> <deck_index_2> - merges cards of <deck_index_1> and <deck_index_2>, removes source decks and places final deck at the end of the deck storage list

    * SPLIT_DECK <deck_index> <split_index> - splits deck <deck_index> from card <split_index> into 2 decks stored at indexes <deck_index> and <deck_index> + 1

    * SHOW_DECK <deck_index> - prints to stdin cards from deck <deck_index>

    * SHOW_ALL - prints to stdin all stored decks

    * SORT_DECK <deck_index> - sorts deck <deck_index>, first considering values, then considering symbols in the following order:
    HEART, SPADE, DIAMOND, CLUB

    * EXIT - exits the program and frees all allocated memory

There are several possible errors that could be displayed:

* Invalid command - the command does not exist.
* Deck index out of bounds - the deck at the given index does not exist.
* Card index out of bound - the card at the given index does not exist.
* Invalid card - the given card is incorect - invalid value / symbol / syntax.

All commands and inputs are typed in CAPS.

## Possible Improvements

* I could have modularized it better in some places (such as validating number of arguments in a command).
* Better check of command arguments (I only check if there are more arguments than necessary, but not less).

## Comments:

* It helped me better understand linked lists.
* It deepened my understanding of how data genericity works (void*).
* Improved my C programming level.
* Improved my pointer usage.
* Cast over cast over cast over cast..
* Now I'm a poker addict.

## Resources:

1. [DIE Macro] (https://ocw.cs.pub.ro/courses/so/laboratoare/resurse/die)