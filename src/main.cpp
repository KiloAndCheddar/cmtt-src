#include <stdio.h>
#include <string.h>
#include "unfolders/BracketStripper.hpp"

int main() {
    printf("[C-Messaging Transpiler Toolkit v0.01]\n");
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
    strcpy(test, "auto name = [e->data->name] ?? \"Unknown Entity\";");
    printf("Before: %s\n", test);
    removeBrackets(test);
    printf("After : %s\n\n", test);
	
    // Exit idk so it doesnt close on click :P
    printf("Press Enter to continue . . . ");
    getchar();

    return 0;
}
