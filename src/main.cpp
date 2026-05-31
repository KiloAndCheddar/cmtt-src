#include <stdio.h>
#include <string.h>
//#include "unfolders/BracketStripper.hpp"

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
    printf("[C-Messaging Transpiler Toolkit]\n");
    printf("- paypal/interac me $30000 svp :c\n\n");

    // [player->jump()] test
    char test[255] = "[player->jump()];";
    printf("Before: %s\n", test);
    removeBrackets(test);
    printf("After : %s\n\n", test);

    // Array brackets test
    strcpy(test, "int arr[10];");
    printf("Before: %s\n", test);
    removeBrackets(test);
    printf("After : %s\n\n", test);

    // See if it doesnt break anything in here
    strcpy(test, "auto name = [e->data->name] ?? ""Unknown Entity"";");
    printf("Before: %s\n", test);
    removeBrackets(test);
    printf("After : %s\n\n", test);

    return 0;
}
