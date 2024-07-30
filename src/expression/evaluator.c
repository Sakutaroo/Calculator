#include <stdio.h>
#include <stdlib.h>
#include "expression.h"

static double eval_expression(list_t **expression);

static void eval_factor(list_t **expression, expression_result_t **result)
{
    if (expression == NULL || (*expression)->next->expression_part == NULL) {
        return;
    }
    if ((*expression)->next->expression_part->operation == NULL && (*expression)->next->expression_part->parentheses == NULL) {
        (*result)->value = (*expression)->next->expression_part->number;
        delete_node_front(expression);
        (*result)->remaining_expression = *expression;
    } else if ((*expression)->next->expression_part->operation && *(*expression)->next->expression_part->operation == ADD) {
        delete_node_front(expression);
        eval_factor(expression, result);
    } else if ((*expression)->next->expression_part->operation && *(*expression)->next->expression_part->operation == SUBTRACT) {
        delete_node_front(expression);
        eval_factor(expression, result);
        (*result)->remaining_expression = *expression;
        (*result)->value = -(*result)->value;
    } else if ((*expression)->next->expression_part->parentheses && *(*expression)->next->expression_part->parentheses == OPENING) {
        delete_node_front(expression);
        (*result)->value = eval_expression(expression);
        delete_node_front(expression);
        (*result)->remaining_expression = *expression;
    }
}

static void eval_term(list_t **expression, expression_result_t **result)
{
    list_t *remaining = NULL;
    double sum = 0.0;

    eval_factor(expression, result);
    remaining = (*result)->remaining_expression;
    sum = (*result)->value;
    while (true) {
        if ((*result)->remaining_expression->next->expression_part != NULL && (*result)->remaining_expression->next->expression_part->operation && *(*result)->remaining_expression->next->expression_part->operation == MULTIPLY) {
            delete_node_front(&remaining);
            eval_factor(&remaining, result);
            sum *= (*result)->value;
            remaining = (*result)->remaining_expression;
        } else if ((*result)->remaining_expression->next->expression_part != NULL && (*result)->remaining_expression->next->expression_part->operation && *(*result)->remaining_expression->next->expression_part->operation == DIVIDE) {
            delete_node_front(&remaining);
            eval_factor(&remaining, result);
            sum /= (*result)->value;
            remaining = (*result)->remaining_expression;
        } else {
            (*result)->remaining_expression = remaining;
            (*result)->value = sum;
            return;
        }
    }
}

void init_expression_result(expression_result_t **result)
{
    if (result == NULL || *result != NULL)
        return;
    *result = malloc(sizeof(expression_result_t));
    (*result)->remaining_expression = NULL;
    (*result)->value = 0.0;
}

static double eval_expression(list_t **expression)
{
    expression_result_t *result = NULL;
    list_t *remaining = NULL;
    double sum = 0.0;

    init_expression_result(&result);
    eval_term(expression, &result);
    remaining = result->remaining_expression;
    sum = result->value;
    while (true) {
        if (result->remaining_expression->next->expression_part != NULL && result->remaining_expression->next->expression_part->operation && *result->remaining_expression->next->expression_part->operation == ADD) {
            delete_node_front(&remaining);
            eval_term(&remaining, &result);
            sum += result->value;
            remaining = result->remaining_expression;
        } else if (result->remaining_expression->next->expression_part != NULL && result->remaining_expression->next->expression_part->operation && *result->remaining_expression->next->expression_part->operation == SUBTRACT) {
            delete_node_front(&remaining);
            eval_term(&remaining, &result);
            sum -= result->value;
            remaining = result->remaining_expression;
        } else {
            free(result);
            return sum;
        }
    }
}

double evaluate(list_t *expression)
{
    if (expression == NULL)
        return 0.0;
    return eval_expression(&expression);
}

