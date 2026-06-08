#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string_view>
#include <vector>
#include "unfolders/BracketStripper.hpp"

int main(int argc, char* argv[]) {

	// get args into a container of views (not incl the executable name)
    std::vector<std::string_view> args(argv + 1, argv + argc);
	
	// interate safely using range-based for loops
    for (const auto& arg : args) {
		
		// Help!
        if (arg == "--help" || arg == "-h") {
			printf("[C-Messaging Transpiler Toolkit v0.01]\n");
            printf("- paypal/interac me $30000 svp :c\n\n");
			
            printf("Usage: cmtt [--help|--h|--version|-v]");
        }
		
		// Version
		if (arg == "--version" || arg == "-v") {
			printf("[C-Messaging Transpiler Toolkit v0.01]\n");
			printf("Copyright (c) 2026, KiloAndCheddar\n");
            printf("- paypal/interac me $30000 svp :c\n\n");
        }
		
		return 0;
    }

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
	
    strcpy(test, "matrix[x][y];");
    printf("Before: %s\n", test);
    removeBrackets(test);
    printf("After : %s\n\n", test);
	
	strcpy(test, "printf(\"[hello]\");");
    printf("Before: %s\n", test);
    removeBrackets(test);
    printf("After : %s\n\n", test);
	
    // Exit idk so it doesnt close on click :P
    printf("Press Enter to continue . . . ");
    getchar();

    return 0;
}
