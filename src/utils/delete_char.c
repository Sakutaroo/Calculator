#include <stdlib.h>

int my_strlen(const char *str)
{
    int length = 0;

    if (str == NULL)
        return 0;
    while (str[length] != '\0') {
        length += 1;
    }
    return length;
}

char *delete_char(const char to_delete, char *str)
{
    char *new_str = NULL;
    int length = my_strlen(str);

    if (to_delete == '\0' || str == NULL)
        return str;
    for (int index = 0; str[index] != '\0'; index += 1)
        if (str[index] == to_delete)
            length -= 1;
    new_str = malloc(sizeof(char) * (length + 1));
    new_str[length] = '\0';
    for (int index_str = 0, index_new = 0; str[index_str] != '\0'; index_str += 1) {
        if (str[index_str] == to_delete)
            continue;
        new_str[index_new] = str[index_str];
        index_new += 1;
    }
    return new_str;
}
