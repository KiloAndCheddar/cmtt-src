#include <string>
#include <cstdio>

// using std::string for now
void process_file(const std::string& input) {
    std::string buffer; 
    bool insideBracket = false; 

    for (char c : input) {
        if (c == '[') {
            insideBracket = true;
            buffer.clear(); // Clear the box
        }
        else if (c == ']') {
            insideBracket = false;
            // Grab our transpiled string back
            std::string result = handle_cmsg_construct(buffer);
            // Write it out fast
            printf("%s", result.c_str());
        }
        else if (insideBracket) {
            buffer += c; // Grab the contents of the []'s
        }
        else {
            putchar(c); // Pass normal code straight through
        }
    }
}

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
