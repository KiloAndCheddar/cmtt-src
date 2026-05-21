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
