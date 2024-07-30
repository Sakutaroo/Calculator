#ifndef PARENTHESES_H
    #define PARENTHESES_H
    #include <stdbool.h>

typedef enum parentheses_s {
    ERROR_PAR,
    OPENING,
    CLOSING
} parentheses_t;

bool is_parentheses(const char c);
parentheses_t parentheses_from_symbol(const char c);

#endif /* PARENTHESES_H */
