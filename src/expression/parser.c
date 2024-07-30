#include <stdlib.h>
#include "list.h"
#include "utils.h"

void parse_number(const char *calculation, int *index, list_t **result)
{
    /* TODO: parse number (warning: 1.3 is valid) */
}

void parse_char(const char *calculation, list_t **result, int *index)
{
    expression_part_t *expression_part = NULL;

    if (result == NULL || index == NULL)
        return;
    if (is_valid_symbol(calculation[*index]) == true) {
        init_expression_part_operation(&expression_part, operation_from_symbol(calculation[*index]));
        create_node_back(result, expression_part);
    } else if (is_digit(calculation[*index])) {
        parse_number(calculation, index, result);
        /* TODO: add to result the number */
    } else if (is_parentheses(calculation[*index])) {
        init_expression_part_parentheses(&expression_part, parentheses_from_symbol(calculation[*index]));
        create_node_back(result, expression_part);
    }
}

list_t *parse(const char *calculation)
{
    list_t *result = NULL;

    if (calculation == NULL)
        return NULL;
    create_head(&result);
    for (int index = 0; calculation[index] != '\0' ; index += 1) {
        parse_char(calculation, &result, &index);
        /* TODO: if it was a number: not increment index */
    }
    return result;
}
