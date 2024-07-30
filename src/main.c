#include <stdio.h>
#include <stdlib.h>
#include <utils.h>

#include "expression_part.h"
#include "operation.h"
#include "expression.h"
#include "list.h"
#include "calculator.h"

int main(const int argc, char **argv)
{
    // if (argc != 2 || argv == NULL || *argv == NULL || argv[1] == NULL)
    //     return 1;

    printf("%f\n", convert_str_to_double("561.556+"));

    return 0;
}
