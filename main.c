#include "strings.h"
#include "io.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//forward declaration
void assert_reversed();
void assert_truncated();
void assert_eprintf();

int main() {
    assert_reversed();
    assert_truncated();
    assert_eprintf();
    return 0;
}

void assert_reversed() {
    char* my_string = "Hello!";
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
    char* my_string = "Hello!";
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

void assert_eprintf() {
    char buffer[100];
    size_t bufsize = sizeof(buffer);
    FILE* tempfs_file = fmemopen(buffer, bufsize, "w");
    setbuf(tempfs_file, NULL);
    stderr = tempfs_file; //redirect stderr to the buffer "file" in memory
    
    eprintf("This is an %s", "error");

    fflush(stderr);
    if (strcmp(buffer, "This is an error") == 0) {
        puts("[tests] eprintf passed!");
    }
    else {
        puts("[tests] eprintf failed!");
        printf("eprintf output: %s\n", buffer);
    }
    
    stderr = fdopen(2, "w"); //restore stderr
    fclose(tempfs_file);
}
