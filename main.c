#include "strings.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//forward declaration
void assert_reversed();
void assert_truncated();

int main() {
    assert_reversed();
    assert_truncated();
}

void assert_reversed() {
    const char* my_string = "Hello!";
    char* reversed = strrev(my_string);
    
    if (strcmp(reversed, "!olleH") == 0) {
        puts("[tests] strrev passed!");
    }
    else {
        puts("[tests] strrev failed!");
        printf("strrev input: %s\nstrrev output: %s\n", my_string, reversed);
    }
    
    free(reversed);
}

void assert_truncated() {
    const char* my_string = "Hello!";
    char* truncated = strtrunc(my_string, 3);
    
    if (strcmp(truncated, "Hel") == 0) {
        puts("[tests] strtrunc passed!");
    }
    else {
        puts("[tests] strtrunc failed!");
        printf("strtrunc input: %s\nstrtrunc output: %s\n", my_string, truncated);
    }

    free(truncated);
}
