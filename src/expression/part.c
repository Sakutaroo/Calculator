#include <stdlib.h>
#include "expression_part.h"

int delete_expression_part(expression_part_t **expression_part)
{
    if (expression_part == NULL || *expression_part == NULL)
        return 1;
    if ((*expression_part)->operation != NULL)
        free((*expression_part)->operation);
    if ((*expression_part)->parentheses != NULL)
        free((*expression_part)->parentheses);
    free(*expression_part);
    return 0;
}

static int init_expression_part(expression_part_t **expression_part)
{
    if (*expression_part != NULL)
        return 1;
    *expression_part = malloc(sizeof(expression_part_t));
    (*expression_part)->number = 0;
    (*expression_part)->operation = NULL;
    (*expression_part)->parentheses = NULL;
    return 0;
}

int init_expression_part_operation(expression_part_t **expression_part, operation_t operation)
{
    if (expression_part == NULL || *expression_part != NULL)
        return 1;
    init_expression_part(expression_part);
    (*expression_part)->operation = malloc(sizeof(operation_t));
    (*expression_part)->operation = &operation;
    return 0;
}

int init_expression_part_parentheses(expression_part_t **expression_part, parentheses_t parentheses)
{
    if (expression_part == NULL || *expression_part != NULL)
        return 1;
    init_expression_part(expression_part);
    (*expression_part)->parentheses = malloc(sizeof(parentheses_t));
    (*expression_part)->parentheses = &parentheses;
    return 0;
}

int init_expression_part_number(expression_part_t **expression_part, double number)
{
    if (expression_part == NULL || *expression_part != NULL)
        return 1;
    init_expression_part(expression_part);
    (*expression_part)->number = number;
    return 0;
}
