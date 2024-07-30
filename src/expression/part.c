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

int init_expression_part(expression_part_t **expression_part)
{
    if (expression_part == NULL || *expression_part != NULL)
        return 1;
    *expression_part = malloc(sizeof(expression_part_t));
    (*expression_part)->number = 0;
    (*expression_part)->operation = NULL;
    (*expression_part)->parentheses = NULL;
    return 0;
}
