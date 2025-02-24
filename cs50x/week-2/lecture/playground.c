#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    // const string input = get_string("Input:  ");
    const string input = argv[1];
    if (argc < 2) {
        printf("Please give a string in argument.\n");
        return 1;
    }
    string output = input;

    // Uppercase
    for (int i = 0, n = strlen(input); i < n; i++)
    {
        output[i] = input[i] >= 'a' && input[i] <= 'z' ? input[i] - 32 : input[i];
    }

    printf("Output: %s\n", output);
    return 0;
}
