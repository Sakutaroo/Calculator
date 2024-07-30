#ifndef EXPRESSION_PART_H
    #define EXPRESSION_PART_H
    #include "operation.h"

typedef enum parentheses_s {
    OPENING,
    CLOSING
} parentheses_t;

typedef struct expression_part_s {
    double number;
    operation_t *operation;
    parentheses_t *parentheses;
} expression_part_t;

int delete_expression_part(expression_part_t **expression_part);
int init_expression_part(expression_part_t **expression_part);

#endif /* EXPRESSION_PART_H */
