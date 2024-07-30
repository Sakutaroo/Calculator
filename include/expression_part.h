#ifndef EXPRESSION_PART_H
    #define EXPRESSION_PART_H
    #include "operation.h"
    #include "parentheses.h"

typedef struct expression_part_s {
    double number;
    operation_t *operation;
    parentheses_t *parentheses;
} expression_part_t;

int delete_expression_part(expression_part_t **expression_part);
int init_expression_part_operation(expression_part_t **expression_part, operation_t operation);
int init_expression_part_parentheses(expression_part_t **expression_part, parentheses_t parentheses);
int init_expression_part_number(expression_part_t **expression_part, double number);

#endif /* EXPRESSION_PART_H */
