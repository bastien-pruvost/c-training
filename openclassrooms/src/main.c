#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "calculation.h"
#include "user.h"
#include "utils.h"

#define USER_COUNT 2

// Main function
int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    // --- Define a variable ---
    printf("--- Define a variable ---\n");

    int age = 0;

    printf("'age' value = %d \n", age);
    printf("'age' address = %p \n", &age);

    // ---------------------------------------------------------------------------------------------------------------

    // --- Ask for a variable ---
    printf("\n--- Ask for a variable ---\n");

    printf("Enter your age : ");
    scanf("%d", &age);

    printf("'age' value = %d \n", age);
    printf("'age' address = %p \n", &age);

    // ---------------------------------------------------------------------------------------------------------------

    // --- Add numbers ---
    printf("\n--- Add numbers ---\n");

    const int x = 5;
    const int y = 2;
    const int add = x + y;
    const double divide = (double)x / y;

    // %f Affiche un float en notation scientifique
    // %g l'affiche sans les zéros inutiles à la fin
    // %.5g l'affiche avec 5 chiffres après la virgules
    printf("%d + %d = %d\n", x, y, add);
    printf("%d / %d = %g\n", x, y, divide);

    // ---------------------------------------------------------------------------------------------------------------

    // --- Define and use functions ---
    printf("\n--- Define and use functions ---\n");

    const int baseNumber = 5;
    const int doubledNumber = doubleNumber(baseNumber);

    printf("Base = %d\n", baseNumber);
    printf("Double = %d\n", doubledNumber);

    // ---------------------------------------------------------------------------------------------------------------

    // --- Define a pointer ---
    printf("\n--- Define a pointer ---\n");

    // We put the address of age (&age) in the pointer (*agePointer)
    int *agePointer = &age;

    printf("'agePointer' target = %p (address of 'age') \n", agePointer);
    printf("'agePointer' address = %p (address of 'agePointer') \n",
           &agePointer);
    printf("'agePointer' target value = %d (value of 'age') \n", *agePointer);

    // ---------------------------------------------------------------------------------------------------------------

    // --- Pass a pointer to a function ---
    printf("\n--- Pass a pointer to a function ---\n");

    int myNumber = 10;

    printf("myNumber = %d \n", myNumber);

    // We can pass directly the address of the variable
    tripleNumber(&myNumber);

    printf("myNumber after passing through tripleNumber fn = %d \n", myNumber);

    // We can also define a pointer before passing it to the function
    int *myNumberPointer = &myNumber;

    tripleNumber(myNumberPointer);

    printf("myNumber after passing through tripleNumber fn = %d \n", myNumber);

    int printedArray[] = {2, 4, 6, 8};
    printArray(printedArray, 4);

    // ---------------------------------------------------------------------------------------------------------------

    // Define an array
    printf("\n--- Define an array ---\n");

    int array[] = {0, 16, 32, 48, 65};

    const int sum = arraySum(array, 5);
    const double average = arrayAverage(array, 5);

    printf("La somme des valeurs du tableau est : %d \n", sum);
    printf("La moyenne des valeurs du tableau est : %lf \n", average);

    // ---------------------------------------------------------------------------------------------------------------

    // Define a char
    printf("\n--- Define a char ---\n");

    const char letter = 'C';
    printf("%d\n", letter);
    printf("%c\n", letter);

    // ---------------------------------------------------------------------------------------------------------------

    // Define a string
    printf("\n--- Define a string ---\n");

    char *myString = "test string";
    printString(myString);

    // ---------------------------------------------------------------------------------------------------------------

    // Prompt user for a string
    printf("\n--- Prompt user for a string ---\n");

    char userString[99];
    printf("Type a string: ");
    scanf("%s", userString);
    printf("%s\n", userString);

    // ---------------------------------------------------------------------------------------------------------------

    // Struct and typedef (defined in users.h)
    printf("\n--- Use a struct ---\n");

    User users[USER_COUNT];

    for (int i = 0; i < USER_COUNT; i++)
    {
        User *current = &(users[i]);
        assignValuesToUser(current, i + 1);
    }

    for (int i = 0; i < USER_COUNT; i++)
    {
        printf("User id: %d\n", users[i].id);
        printf("User name: %s\n", users[i].firstname);
        printf("User lastname: %s\n", users[i].lastname);
        printf("User age: %d\n\n", users[i].age);
    }

    // ---------------------------------------------------------------------------------------------------------------

    // Enum (defined in users.h)
    printf("\n--- Use an enum ---\n");

    for (int i = 0; i < USER_COUNT; i++)
    {
        if (users[i].role == ADMIN)
        {
            printf("User %d (%s) is admin !\n", i + 1, users[i].firstname);
        }
        else
        {
            printf("User %d (%s) is NOT admin !\n", i + 1, users[i].firstname);
        }
    }

    // ---------------------------------------------------------------------------------------------------------------

    // Files (defined in users.h)
    printf("\n--- Work with files ---\n");

    return 0;
}
