#include <stdlib.h>
#include "list.h"
#include "utils.h"

static double parse_number(const char *calculation, int *index)
{
    const double number = convert_str_to_double(&calculation[*index]);

    while (is_digit(calculation[*index]) || calculation[*index] == '.') {
        *index += 1;
    }
    *index -= 1;
    return number;
}

static void parse_char(const char *calculation, list_t **result, int *index)
{
    expression_part_t *expression_part = NULL;

    if (is_valid_symbol(calculation[*index]) == true) {
        init_expression_part_operation(&expression_part, operation_from_symbol(calculation[*index]));
        create_node_back(result, expression_part);
    } else if (is_digit(calculation[*index])) {
        const double number = parse_number(calculation, index);
        init_expression_part_number(&expression_part, number);
        create_node_back(result, expression_part);
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
    for (int index = 0; calculation[index] != '\0' ; index += 1)
        parse_char(calculation, &result, &index);
    return result;
}
