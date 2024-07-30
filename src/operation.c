#include "operation.h"

bool is_valid_symbol(const char symbol)
{
    for (int index = 0; op_map[index].operation != ERROR; index += 1) {
        if (symbol == op_map[index].symbol) {
            return true;
        }
    }
    return false;
}

operation_t operation_from_symbol(const char symbol)
{
    for (int index = 0; op_map[index].operation != ERROR; index += 1) {
        if (symbol == op_map[index].symbol) {
            return op_map[index].operation;
        }
    }
    return ERROR;
}
