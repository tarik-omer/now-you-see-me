// Copyright 2021 - 2022 Omer Tarik Ilhan 314CA
#include <stdio.h>

void DECK_INDEX_OUT_OF_BOUNDS()
{
    printf("The provided index is out of bounds for the deck list.\n");
}

void CARD_INDEX_OUT_OF_BOUNDS(int index)
{
    printf("The provided index is out of bounds for deck %d.\n", index);
}

void INVALID_CARD()
{
    printf("The provided card is not a valid one.\n");
}

void INVALID_COMMAND()
{
    printf("Invalid command. Please try again.\n");
}
