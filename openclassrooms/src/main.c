#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "buffer.h"
#include "calculation.h"
#include "linked-list.h"
#include "user.h"
#include "utils.h"

#define USER_COUNT 1
#define MAX_STR_LENGTH 255

void prompt_user_str(char *str, int length);

int main(int argc, char *argv[]) {
  (void)argc;
  (void)argv;

  // --- Define a variable ---
  printf("--- Define a variable ---\n");

  int age = 0;

  printf("'age' value = %d \n", age);
  printf("'age' address = %p \n", &age);

  // ---------------------------------------------------------------------------------

  // --- Ask for a variable ---
  printf("\n--- Ask for a variable ---\n");

  printf("Enter your age : ");
  scanf("%d", &age);

  printf("'age' value = %d \n", age);
  printf("'age' address = %p \n", &age);

  // ---------------------------------------------------------------------------------

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

  // ---------------------------------------------------------------------------------

  // --- Define and use functions ---
  printf("\n--- Define and use functions ---\n");

  const int baseNumber = 5;
  const int doubledNumber = doubleNumber(baseNumber);

  printf("Base = %d\n", baseNumber);
  printf("Double = %d\n", doubledNumber);

  // ---------------------------------------------------------------------------------

  // --- Define a pointer ---
  printf("\n--- Define a pointer ---\n");

  // We put the address of age (&age) in the pointer (*agePointer)
  int *agePointer = &age;

  printf("'agePointer' target = %p (address of 'age') \n", agePointer);
  printf("'agePointer' address = %p (address of 'agePointer') \n", &agePointer);
  printf("'agePointer' target value = %d (value of 'age') \n", *agePointer);

  // ---------------------------------------------------------------------------------

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

  // ---------------------------------------------------------------------------------

  // Define an array
  printf("\n--- Define an array ---\n");

  int array[] = {0, 16, 32, 48, 65};

  const int sum = arraySum(array, 5);
  const double average = arrayAverage(array, 5);

  printf("La somme des valeurs du tableau est : %d \n", sum);
  printf("La moyenne des valeurs du tableau est : %lf \n", average);

  // ---------------------------------------------------------------------------------

  // Define a char
  printf("\n--- Define a char ---\n");

  const char letter = 'C';
  printf("%d\n", letter);
  printf("%c\n", letter);

  // ---------------------------------------------------------------------------------

  // Define a string
  printf("\n--- Define a string ---\n");

  char *myString = "test string";
  printString(myString);

  // ---------------------------------------------------------------------------------

  // Prompt user for a string
  printf("\n--- Prompt user for a string ---\n");

  char userString[99];
  printf("Type a string: ");
  scanf("%s", userString);
  printf("%s\n", userString);

  // ---------------------------------------------------------------------------------

  // Struct and typedef (defined in users.h)
  printf("\n--- Use a struct ---\n");

  User users[USER_COUNT] = {0};

  for (int i = 0; i < USER_COUNT; i++) {
    User *current = &(users[i]);
    assignValuesToUser(current, i + 1);
  }

  for (int i = 0; i < USER_COUNT; i++) {
    printf("User id: %d\n", users[i].id);
    printf("User name: %s\n", users[i].firstname);
    printf("User lastname: %s\n", users[i].lastname);
    printf("User age: %d\n\n", users[i].age);
  }

  // ---------------------------------------------------------------------------------

  // Enum (defined in users.h)
  printf("\n--- Use an enum ---\n");

  for (int i = 0; i < USER_COUNT; i++) {
    if (users[i].role == ADMIN) {
      printf("User %d (%s) is admin !\n", i + 1, users[i].firstname);
    } else {
      printf("User %d (%s) is NOT admin !\n", i + 1, users[i].firstname);
    }
  }

  // ---------------------------------------------------------------------------------

  // Write in a file
  printf("\n--- Write in a file ---\n");

  FILE *file_write = NULL;

  file_write = fopen("assets/write.txt", "a");

  if (file_write == NULL) {
    printf("Unable to open file %s", "assets/write.txt");
    return EXIT_FAILURE;
  }

  // Write a char in the file
  fputc('\n', file_write);
  // Write a char in the file
  fputc('B', file_write);

  // Write a string in the file
  fputs("\nSalut les développeurs\nBienvenue sur OpenClassrooms !", file_write);

  for (int i = 0; i < USER_COUNT; i++) {
    if (users[i].role == ADMIN) {
      // Write a formatted string in the file
      fprintf(file_write, "\nUser %d (%s) is admin !", i + 1,
              users[i].firstname);
    } else {
      // Write a formatted string in the file
      fprintf(file_write, "\nUser %d (%s) is NOT admin !", i + 1,
              users[i].firstname);
    }
  }

  fclose(file_write);

  // ---------------------------------------------------------------------------------

  // Read a file
  printf("\n--- Read a file ---\n");

  // Read char
  FILE *file_read_char = NULL;

  file_read_char = fopen("assets/read.txt", "r");

  if (file_read_char == NULL) {
    printf("Unable to open file %s", "assets/read.txt");
    return EXIT_FAILURE;
  }

  char character = fgetc(file_read_char);  // fgetc read ONE char

  while (character != EOF) {  // EOF = End of file
    printf("%c", character);
    character = fgetc(file_read_char);
  }

  fclose(file_read_char);

  // Read string
  FILE *file_read_str = NULL;
  file_read_str = fopen("assets/read.txt", "r");

  char string[MAX_STR_LENGTH] = "";

  while (fgets(string, MAX_STR_LENGTH, file_read_str) != NULL) {
    printf("%s", string);
  }

  fclose(file_read_str);

  // Read formatted string
  FILE *file_read_formatted_str = NULL;
  file_read_formatted_str = fopen("assets/scores.txt", "r");
  int scores[3] = {0};

  while (fscanf(file_read_formatted_str, "%d, %d, %d", &scores[0], &scores[1],
                &scores[2]) != 0) {
    printf("Les scores sont : %d, %d et %d\n", scores[0], scores[1], scores[2]);
    printf("Curseur: %ld\n", ftell(file_read_formatted_str));
  }

  // ---------------------------------------------------------------------------------

  // Memory allocation
  printf("\n--- Memory allocation ---\n");

  int friends_count = 0;
  printf("How much friend: ");
  scanf("%d", &friends_count);

  int *int_arr = malloc(friends_count * sizeof(int));

  if (int_arr == NULL) {
    perror("Memory error in int_arr");
    return EXIT_FAILURE;
  }

  for (int i = 0; i < friends_count; i++) {
    printf("Enter age of friend %d: ", i + 1);
    scanf("%d", &(int_arr[i]));
  }

  for (int i = 0; i < friends_count; i++) {
    printf("Friend %d is %d years old !\n", i + 1, int_arr[i]);
  }

  free(int_arr);

  // ---------------------------------------------------------------------------------

  // Strings security
  printf("\n--- Strings security ---\n");

  clearBuffer();

  char safe_name[20];
  int safe_age;

  getString(safe_name, sizeof(safe_name), "Enter your name: ");
  safe_age = getInt("Enter your age: ");

  printf("Hello, %s! You are %d years old.\n", safe_name, safe_age);

  // ---------------------------------------------------------------------------------

  // Linked lists
  printf("\n--- Linked lists ---\n");

  LinkedList *list = createList();
  if (!list) return EXIT_FAILURE;

  insertAtBeginning(list, 30);
  insertAtBeginning(list, 20);
  insertAtBeginning(list, 10);

  printList(list);

  insertAtEnd(list, 50);
  insertAtEnd(list, 60);

  printList(list);

  insertAtPosition(list, 40, 3);

  printList(list);

  deleteFromBeginning(list);
  deleteFromEnd(list);
  deleteFromPosition(list, 2);

  printList(list);

  freeList(list);

  return EXIT_SUCCESS;
}
