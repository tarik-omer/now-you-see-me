// Copyright 2021 - 2022 Omer Tarik Ilhan 314CA
#include "structures.h"

#ifndef DLL_BASE_H_
#define DLL_BASE_H_

doubly_linked_list_t* dll_create(unsigned int data_size);
dll_node_t* dll_get_nth_node(doubly_linked_list_t* list, unsigned int n);
void dll_add_nth_node
(doubly_linked_list_t* list, unsigned int n, const void* data);
dll_node_t* dll_remove_nth_node(doubly_linked_list_t* list, unsigned int n);
unsigned int dll_get_size(doubly_linked_list_t* list);
void dll_free(doubly_linked_list_t** pp_list);
void dll_print_int_list(doubly_linked_list_t* list);

#endif  // DLL_BASE_H_
