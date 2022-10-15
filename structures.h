// Copyright 2021 - 2022 Omer Tarik Ilhan 314CA
#ifndef STRUCTURES_H_
#define STRUCTURES_H_
// each card symbol is associated with a number
#define HEART 0
#define SPADE 1
#define DIAMOND 2
#define CLUB 3
// card information struct
typedef struct card_t
{
    int value;
    int color;
} card_t;
// generic node struct
typedef struct dll_node_t
{
    void* data;

    struct dll_node_t *prev, *next;
} dll_node_t;
// generic list struct
typedef struct doubly_linked_list_t
{
    dll_node_t* head;
    unsigned int data_size;
    unsigned int size;
} doubly_linked_list_t;

// max string size
#define MAX_STR_S 256

#endif  // STRUCTURES_H_
