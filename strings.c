#include <stdlib.h>
#include <string.h>

char* strrev(const char* input) {
    int len = strlen(input);
    char* reversed = malloc(sizeof(char) * (len + 1));

    for (int i = 0; i < len; i++) {
        reversed[(len - 1) - i] = input[i];
    }
    
    reversed[len] = '\0';
    return reversed;
}

char* strtrunc(const char* input, int position) {
    int len = strlen(input);
    char* truncated = malloc(sizeof(char) * (len + 1));
    
    for (int i = 0; i < len; i++) {
        truncated[i] = input[i];
    }

    truncated[len] = '\0';
    if (position < len) {
        truncated[position] = '\0';
    }
    
    return truncated;
}
