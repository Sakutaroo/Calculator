#include <stdbool.h>

bool is_digit(const char c)
{
    if (c >= '0' && c <= '9')
        return true;
    return false;
}
