#include <stddef.h>
#include "utils.h"

double convert_str_to_double(const char *str)
{
    double result = 0.0;
    double fraction = 1.0;
    int index = 0;

    if (str == NULL)
        return result;

    while (is_digit(str[index])) {
        result = result * 10.0 + (str[index] - '0');
        index += 1;
    }
    if (str[index] == '.') {
        index += 1;
        while (is_digit(str[index])) {
            fraction *= 0.1;
            result = result + (str[index] - '0') * fraction;
            index += 1;
        }
    }
    return result;
}
