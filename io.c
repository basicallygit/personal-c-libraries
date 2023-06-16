/*
 * various functions for handling
 * I/O operations
 * 
 */

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

char* readline(const char* prompt) {
    if (prompt != NULL)
        printf("%s", prompt);

    char* input = NULL;
    size_t size = 0;
    size_t capacity = 0;

    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        if (size + 1 >= capacity) {
            capacity += 16;
            char* temp = realloc(input, capacity);
            if (temp == NULL) {
                if (input != NULL) // do not free on first re-alloc
                    free(input);

                return NULL;
            }
            input = temp;
        }
        input[size++] = c;
    }

    input[size] = '\0';

    return input;
}

void eprintf(const char* format, ...) {
    va_list args;
    va_start(args, format);
    vfprintf(stderr, format, args);
    va_end(args);
}
