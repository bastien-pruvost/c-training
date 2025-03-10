#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_ARRAY_LENGTH 3
#define NEW_ARRAY_LENGTH 5

int main(void)
{

    // Define an array of length 3
    int *list = malloc(DEFAULT_ARRAY_LENGTH * sizeof(int));
    if (list == NULL)
    {
        return 1;
    }

    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    // Print this original array of length 3
    for (int i = 0; i < DEFAULT_ARRAY_LENGTH; i++)
    {
        printf("%d\n", list[i]);
    }

    printf("\n");

    // If i want to update the length of the array to 5
    // I create a temp array of length 5 and assign original values to the temp one
    int *tmp = realloc(list, NEW_ARRAY_LENGTH * sizeof(int));
    if (tmp == NULL)
    {
        free(list);
        return 1;
    }

    // I add new values to my temp array
    tmp[3] = 4;
    tmp[4] = 5;

    // I remove the original array (free the memory)
    free(list);

    // I copy the temp array in the original one
    list = tmp;

    // And i print the content
    for (int i = 0; i < NEW_ARRAY_LENGTH; i++)
    {
        printf("%d\n", list[i]);
    }

    // And i remove the temp array (free the memory)
    free(list);
    return 0;
}
