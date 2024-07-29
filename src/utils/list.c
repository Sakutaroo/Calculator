#include <stdlib.h>
#include "list.h"

int create_head(list_t **head)
{
    if (head == NULL || *head != NULL)
        return 84;
    *head = malloc(sizeof(list_t));
    if (*head == NULL)
        return 84;
    (*head)->next = *head;
    (*head)->prev = *head;
    return 0;
}

int create_node_back(list_t **head, int nb)
{
    list_t *node = NULL;

    if (head == NULL || *head == NULL)
        return 84;
    node = malloc(sizeof(list_t));
    if (node == NULL)
        return 84;
    node->number = nb;
    node->next = *head;
    node->prev = (*head)->prev;
    (*head)->prev->next = node;
    (*head)->prev = node;
    return 0;
}

int delete_node_back(list_t **head)
{
    list_t *node =NULL;

    if (head == NULL || *head == NULL)
        return 84;
    node = (*head)->prev;
    if (node == NULL)
        return 84;
    (*head)->prev = node->prev;
    node->prev->next = *head;
    free(node);
    node = NULL;
    return 0;
}

int delete_node_front(list_t **head)
{
    list_t *node = NULL;

    if (head == NULL || *head == NULL)
        return 84;
    node = (*head)->next;
    if (node == NULL)
        return 84;
    (*head)->next = node->next;
    node->next->prev = *head;
    free(node);
    node = NULL;
    return 0;
}

int delete_list(list_t *head)
{
    size_t size = 0;

    if (head == NULL)
        return 84;
    for (const list_t *temp = head->next; head != temp; temp = temp->next)
        size += 1;
    for (size_t i = 0; i < size; i += 1)
        delete_node_back(&head);
    free(head);
    head = NULL;
    return 0;
}
