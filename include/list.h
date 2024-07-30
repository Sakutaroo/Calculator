#ifndef LIST_H
    #define LIST_H
    #include "expression_part.h"

typedef struct list_s {
    expression_part_t *expression_part;
    struct list_s *next;
    struct list_s *prev;
} list_t;

int create_head(list_t **head);
int create_node_back(list_t **head, expression_part_t *expression_part);
int delete_node_back(list_t **head);
int delete_node_front(list_t **head);
int delete_list(list_t *head);
int display_list(const list_t *head);

#endif /* LIST_H */
