#include "parentheses.h"

bool is_parentheses(const char c)
{
    if (c == '(' || c == ')')
        return true;
    return false;
}

parentheses_t parentheses_from_symbol(const char c)
{
    if (c == '(')
        return OPENING;
    if (c == ')')
        return CLOSING;
    return ERROR_PAR;
}
