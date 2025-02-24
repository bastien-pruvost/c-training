#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string strings[] = {"battleship", "boot", "cannon", "iron", "thimble", "top hat"};

    string s = get_string("String to search: ");

    for (int i = 0; i < 6; i++)
    {
        printf("Index: %d\n", i);
        printf("Value: %s\n\n", strings[i]);

        if (strcmp(s, strings[i]))
        {
            printf("Found on index %d!\n", i);
            return 0;
        }
    }
    printf("Not found!\n");
    return 1;
}
