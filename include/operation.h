#ifndef OPERATION_H
    #define OPERATION_H
    #include <stdbool.h>

typedef enum operation_e {
    ERROR_OP,
    ADD,
    SUBTRACT,
    MULTIPLY,
    DIVIDE
} operation_t;

typedef struct op_s {
    char symbol;
    operation_t operation;
} op_t;

static const op_t op_map[] = {
    {.symbol = '+', .operation = ADD},
    {.symbol = '-', .operation = SUBTRACT},
    {.symbol = 'x', .operation = MULTIPLY},
    {.symbol = '/', .operation = DIVIDE},
    {.symbol = '\0', .operation = ERROR_OP}
};

operation_t operation_from_symbol(const char symbol);
bool is_valid_symbol(const char symbol);

#endif /* OPERATION_H */
