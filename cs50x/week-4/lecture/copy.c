#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *s = get_string("s: ");

    int s_length = strlen(s);

    char *t = malloc(s_length + 1);

    if (t == NULL)
    {
        printf("Malloc error");
        return 1;
    }

    // for (int i = 0; i < s_length + 1; i++)
    // {
    //     t[i] = s[i];
    // }

    strcpy(t, s); // Same as the above commented code (to copy a string)

    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }

    printf("s = %s\n", s);
    printf("t = %s\n", t);

    free(t);
}
