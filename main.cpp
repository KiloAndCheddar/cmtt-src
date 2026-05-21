// #include_once <stdio.h>
// Turns into... 
// ... This! It would be shown in the header file :P
#ifndef _STDIO_INC_GUARD_
#define _STDIO_INC_GUARD_
#include <stdio.h>
#endif

// Code probably would be used in C-Messaging Transpiler Toolkit
void removeBrackets(char *str) {
    char *src = str; // Pointer to read from
    char *dst = str; // Pointer to write to

    while (*src != '\0') {
        // If the character is NOT a bracket, copy it to dst
        if (*src != '[' && *src != ']') {
            *dst = *src;
            dst++;
        }
        src++;
    }
    // Add the null terminator to mark the new end of the string
    *dst = '\0'; 
}

int main() {
    char myStr[] = "[object->method()];";
    
    printf("Before: %s\n", myStr);
    removeBrackets(myStr);
    printf("After : %s\n", myStr);

    return 0;
}
