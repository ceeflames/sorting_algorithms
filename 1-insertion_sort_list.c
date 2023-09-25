#include "sort.h"
#include <stddef.h>
#include <stdlib.h>

/* Function to create a new node */
listint_t *create_node(int n) {
    listint_t *new_node = malloc(sizeof(listint_t));
    if (new_node == NULL)
        return NULL;

    new_node->n = n;
    new_node->prev = NULL;
    new_node->next = NULL;

    return new_node;
}

/* Function to perform insertion sort on a doubly linked list */
void insertion_sort_list(listint_t **list) {
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    listint_t *current, *prev, *temp;

    current = (*list)->next;

    while (current != NULL) {
        prev = current->prev;
        temp = current;

        while (prev != NULL && prev->n > temp->n) {
            /* Swap the nodes */
            if (prev->prev != NULL)
                prev->prev->next = temp;
            if (temp->next != NULL)
                temp->next->prev = prev;
            prev->next = temp->next;
            temp->prev = prev->prev;
            prev->prev = temp;
            temp->next = prev;

            if (temp->prev == NULL)
                *list = temp;

            print_list(*list); /* Print the list after each swap */

            prev = temp->prev;
        }

        current = current->next;
    }
}

/* Function to print the doubly linked list */
void print_list(const listint_t *list) {
    const listint_t *current = list;

    while (current != NULL) {
        printf("%d", current->n);
        if (current->next != NULL)
            printf(", ");
        current = current->next;
    }
    printf("\n");
}
