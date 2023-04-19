#include <stdlib.h>
#include <string.h>

char* strrev(char* input) {
    int len = strlen(input);
    char* reversed = malloc(sizeof(char) * (len + 1));
    
    if (reversed == NULL)
        abort();

    for (int i = 0; i < len; i++)
        reversed[(len - 1) - i] = input[i];

    reversed[len] = '\0';
    return reversed;
}

char* strtrunc(char* input, int position) {
    int len = strlen(input);
    
    if (position >= len) //no need for allocating a new string
        return input;
    
    char* truncated = malloc(sizeof(char) * position + 1);

    if (truncated == NULL)
        abort();

    for (int i = 0; i < position; i++)
        truncated[i] = input[i];

    truncated[position] = '\0';
    return truncated;
}
