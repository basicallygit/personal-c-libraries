#include <stdio.h>
#include <stdarg.h>

void eprintf(const char* format, ...) {
    va_list args;
    va_start(args, format);
    vfprintf(stderr, format, args);
    va_end(args);
}
