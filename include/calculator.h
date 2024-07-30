#ifndef CALCULATOR_H
    #define CALCULATOR_H
    #include "list.h"

typedef struct calculator_s {
} calculator_t;

list_t *parse(const char *calculation);
double evaluate(list_t *expression);

#endif /* CALCULATOR_H */
