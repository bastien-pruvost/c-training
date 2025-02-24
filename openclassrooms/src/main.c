#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "calculation.h"

// Function prototypes
int arraySum(int array[], int arrayLength);
double arrayAverage(int array[], int arrayLength);

// Main function
int main(int argc, char *argv[])
{
  (void)argc;
  (void)argv;

  // --- Define a variable ---
  printf("--- Define a variable --- \n");

  int age = 0;

  printf("'age' value = %d \n", age);
  printf("'age' address = %p \n\n", &age);

  // ---------------------------------------------------------------------------------------------------------------

  // --- Ask for a variable ---
  printf("--- Ask for a variable --- \n");

  printf("Enter your age : ");
  scanf("%d", &age);

  printf("'age' value = %d \n", age);
  printf("'age' address = %p \n\n", &age);

  // ---------------------------------------------------------------------------------------------------------------

  // --- Add numbers ---
  printf("--- Add numbers --- \n");

  const int x = 5;
  const int y = 2;
  const int add = x + y;
  const double divide = (double)x / y;

  // %f Affiche un float en notation scientifique
  // %g l'affiche sans les zéros inutiles à la fin
  // %.5g l'affiche avec 5 chiffres après la virgules
  printf("%d + %d = %d\n", x, y, add);
  printf("%d / %d = %g\n\n", x, y, divide);

  // ---------------------------------------------------------------------------------------------------------------

  // --- Define and use functions ---
  printf("--- Define and use functions --- \n");

  const int baseNumber = 5;
  const int doubledNumber = doubleNumber(baseNumber);

  printf("Base = %d\n", baseNumber);
  printf("Double = %d\n\n", doubledNumber);

  // ---------------------------------------------------------------------------------------------------------------

  // --- Define a pointer ---
  printf("--- Define a pointer --- \n");

  // We put the address of age (&age) in the pointer (*agePointer)
  int *agePointer = &age;

  printf("'agePointer' target = %p (address of 'age') \n", agePointer);
  printf("'agePointer' address = %p (address of 'agePointer') \n", &agePointer);
  printf("'agePointer' target value = %d (value of 'age') \n\n", *agePointer);

  // ---------------------------------------------------------------------------------------------------------------

  // --- Pass a pointer to a function ---
  printf("--- Pass a pointer to a function --- \n");

  int myNumber = 10;

  printf("myNumber = %d \n", myNumber);

  // We can pass directly the address of the variable
  tripleNumber(&myNumber);

  printf("myNumber after passing through tripleNumber fn = %d \n", myNumber);

  // We can also define a pointer before passing it to the function
  int *myNumberPointer = &myNumber;

  tripleNumber(myNumberPointer);

  printf("myNumber after passing through tripleNumber fn = %d \n\n", myNumber);

  // ---------------------------------------------------------------------------------------------------------------

  // Define an array
  // int array[] = {0, 16, 32, 48, 65};

  // const int sum = arraySum(array, 5);
  // const double average = arrayAverage(array, 5);

  // printf("La somme des valeurs du tableau est : %d \n", sum);
  // printf("La moyenne des valeurs du tableau est : %lf \n", average);

  // ---------------------------------------------------------------------------------------------------------------

  // const char letter = 'C';
  // printf("%d \n", letter);

  return 0;
}

int arraySum(int array[], int arrayLength)
{
  int sum = 0;

  for (int i = 0; i < (arrayLength); i++)
  {
    sum += array[i];
  }

  return sum;
}

double arrayAverage(int array[], int arrayLength)
{
  int sum = 0;

  for (int i = 0; i < (arrayLength); i++)
  {
    sum += array[i];
  }

  return (double)sum / (double)arrayLength;
}