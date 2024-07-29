#ifndef LIST_H
    #define LIST_H

typedef struct list_s {
    int number;
    struct list_s *next;
    struct list_s *prev;
} list_t;

int create_head(list_t **head);
int create_node_back(list_t **head, int nb);
int delete_node_back(list_t **head);
int delete_node_front(list_t **head);
int delete_list(list_t *head);

#endif /* LIST_H */
