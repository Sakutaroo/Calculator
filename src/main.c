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
    list_t *list = NULL;

    if (argc != 2 || argv == NULL || *argv == NULL || argv[1] == NULL)
        return 1;
    list = parse(argv[1]);
    display_list(list);
    delete_list(list);
    return 0;
}
