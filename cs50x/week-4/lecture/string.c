#include <stdio.h>

int main(void)
{
    char *s = "Hi!"; // s is a pointer to an array of char created somewhere in the memory
    printf("%p\n", &s); // Address of the pointer (useless)
    printf("%p\n\n", s); // Value of the pointer (address of the 1st char of the string)

    printf("%p\n", &s[0]); // Address of the 1st char of the string (same as s, because s is targeting the 1st char)
    printf("%p\n", &s[1]); // Address of the 2nd char ''
    printf("%p\n", &(s[2])); // Address of the 3rd char ''
    printf("%p\n\n", &(s[3])); // Address of the 4th char ''

    printf ("%s\n\n", s); // Value of the string (it's an address but printed as a string with %s)

    printf ("%c\n", s[0]); // Value of the 1st char (%c to print char)
    printf ("%c\n", s[1]); // Value of the 2nd char
    printf ("%c\n\n", s[2]); // Value of the 3rd char

    // Same as above
    printf("%c\n", *s); // Value of the target of the pointer s (value of the 1st char of the string)
    printf("%c\n", *(s + 1)); // Value of the target of the pointer s + 1 (value of the 2nd char of the string)
    printf("%c\n", *(s + 2)); // Value of the target of the pointer s + 1 (value of the 2nd char of the string)
}





