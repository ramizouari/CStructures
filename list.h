//
// Created by ramizouari on 02/04/2022.
//

#ifndef CSTRUCTURES_LIST_H
#define CSTRUCTURES_LIST_H
#include <stdlib.h>
#include <stddef.h>

typedef struct list_node {
    void *data;
    struct list_node *next;
} list_node_t,*list_t;

list_t list_create(void) {
    return NULL;
}

list_t list_insert(list_t list, void *data) {
    list_node_t *node = malloc(sizeof(list_node_t));
    node->data = data;
    node->next = list;
    return node;
}

list_t list_erase(list_t list, void *data) {
    list_node_t *node = list;
    list_node_t *prev = NULL;
    while (node != NULL) {
        if (node->data == data) {
            if (prev == NULL) {
                list = node->next;
            } else {
                prev->next = node->next;
            }
            free(node);
            return list;
        }
        prev = node;
        node = node->next;
    }
    return list;
}

list_t list_destroy(list_t list) {
    list_node_t *node = list;
    while (node != NULL) {
        list = node->next;
        free(node);
        node = list;
    }
    return NULL;
}

list_t list_find(list_t list, void *data) {
    list_node_t *node = list;
    while (node != NULL) {
        if (node->data == data) {
            return node;
        }
        node = node->next;
    }
    return NULL;
}

list_t list_reverse(list_t list) {
    list_node_t *node = list;
    list_node_t *prev = NULL;
    while (node != NULL) {
        list_node_t *next = node->next;
        node->next = prev;
        prev = node;
        node = next;
    }
    return prev;
}


#endif //CSTRUCTURES_LIST_H
