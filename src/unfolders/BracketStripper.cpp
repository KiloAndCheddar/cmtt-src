//#include <stdio.h>
//#include <string.h> // strlen() or strcpy().
//#include <stdlib.h> // Dynamically allocating memory for strings.
//#include <ctype.h>  // Check if characters are alphanumeric.

// I should NOT have slept through the cpp tutorials frfr
// BracketStripper.cpp.cpp
#include "BracketStripper.hpp"

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
