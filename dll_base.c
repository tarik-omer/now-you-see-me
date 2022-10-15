// Copyright 2021 - 2022 Omer Tarik Ilhan 314CA
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"
#include "utils.h"

// basic list functions
doubly_linked_list_t* dll_create(unsigned int data_size)
{
    doubly_linked_list_t* list = malloc(sizeof(doubly_linked_list_t));
    DIE(list == NULL, "List malloc failed\n");
    list->data_size = data_size;
    list->head = NULL;
    list->size = 0;

    return list;
}

dll_node_t* dll_get_nth_node(doubly_linked_list_t* list, unsigned int n)
{
    if (!list->size)
        return NULL;

    n = n % list->size;
    dll_node_t* it = list->head;

    for (unsigned int i = 0; i < n; i++)
        it = it->next;

    return it;
}

void
dll_add_nth_node(doubly_linked_list_t* list, unsigned int n, const void* data)
{
    if (list == NULL) {
        // case: bad list
        printf("Bad list\n");
        return;
    }

    // place data into the new node
    dll_node_t* newNode = malloc(sizeof(dll_node_t));
    DIE(newNode == NULL, "Node malloc failed\n");
    newNode->data = malloc(list->data_size);
    DIE(newNode->data == NULL, "Data malloc failed\n");
    memcpy(newNode->data, data, list->data_size);

    newNode->next = NULL;
    newNode->prev = NULL;

    if (n > list->size)
        n = list->size;

    if (list->size == 0) {
        // case: empty list
        list->head = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;

    } else if (list->size > 0 && n == 0) {
        // case: first element
        newNode->next = list->head;
        newNode->prev = list->head->prev;
        list->head->prev->next = newNode;
        list->head = newNode;

    } else if (n == list->size) {
        // case: last element
        newNode->next = list->head;
        newNode->prev = list->head->prev;
        list->head->prev->next = newNode;
        list->head->prev = newNode;

    } else {
        // case: middle element
        dll_node_t* tmp = dll_get_nth_node(list, n - 1);
        newNode->next = tmp->next;
        newNode->prev = tmp;
        tmp->next->prev = newNode;
        tmp->next = newNode;
    }
    list->size++;
}

dll_node_t* dll_remove_nth_node(doubly_linked_list_t* list, unsigned int n)
{
    // check for an empty / bad list
    if (list == NULL || list->size == 0) {
        printf("Problems amigo\n");
        return NULL;
    }

    // truncate the index to the list size
    if (n > list->size - 1)
        n = list->size - 1;

    dll_node_t* tmp;

    if (n == 0) {
        // case: first element
        tmp = list->head;

        if (list->size == 1) {
            list->head = NULL;

        } else {
        list->head->prev->next = tmp->next;
        list->head->next->prev = tmp->prev;
        list->head = tmp->next;
        }

    } else if (n == list->size - 1) {
        // case: last element
        tmp = list->head->prev;
        list->head->prev->prev->next = list->head;
        list->head->prev = tmp->prev;

    } else {
        // case: middle element
        dll_node_t* it = dll_get_nth_node(list, n - 1);
        tmp = it->next;
        it->next->next->prev = it;
        it->next = tmp->next;
    }

    tmp->next = NULL;
    tmp->prev = NULL;
    list->size--;
    return tmp;
}

unsigned int dll_get_size(doubly_linked_list_t* list)
{
    return list->size;
}

void dll_free(doubly_linked_list_t** pp_list)
{
    doubly_linked_list_t* list = *pp_list;
    if (list->size == 0) {
        free(list);
        return;
    }
    dll_node_t* it = list->head;
    // break the list cycle
    it->prev->next = NULL;
    // iterate to the end
    while (it != NULL) {
        dll_node_t* tmp = it;
        it = it->next;
        free(tmp->data);
        free(tmp);
    }
    free(list);
}
