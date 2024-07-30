#ifndef EXPRESSION_H
    #define EXPRESSION_H
    #include "list.h"

typedef struct expression_result_s {
    list_t *remaining_expression;
    double value;
} expression_result_t;

#endif /* EXPRESSION_H */
