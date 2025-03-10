#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "buffer.h"

void printString(char *str) { printf("%s\n", str); }

void printArray(int arr[], int length) {
  for (int i = 0; i < length; i++) {
    printf("%d\n", arr[i]);
  }
}

int arraySum(int array[], int arrayLength) {
  int sum = 0;

  for (int i = 0; i < (arrayLength); i++) {
    sum += array[i];
  }

  return sum;
}

double arrayAverage(int array[], int arrayLength) {
  int sum = 0;

  for (int i = 0; i < (arrayLength); i++) {
    sum += array[i];
  }

  return (double)sum / (double)arrayLength;
}

void getString(char *str, size_t length, const char *prompt) {
  printf("%s", prompt);
  if (fgets(str, length, stdin) == NULL) {
    printf("Error reading input.\n");
    str[0] = '\0';  // Ensure string is empty on failure
    return;
  }

  // Remove newline if present
  str[strcspn(str, "\n")] = '\0';

  // If input was too long, clear buffer
  if (strlen(str) == length - 1 && str[length - 2] != '\n') {
    clearBuffer();
  }
}

int getInt(const char *prompt) {
  char buffer[20];
  int num;
  while (1) {
    printf("%s", prompt);
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
      printf("Error reading input.\n");
      continue;
    }

    char *endptr;
    num = strtol(buffer, &endptr, 10);
    if (endptr == buffer || *endptr != '\n') {
      printf("Invalid number. Try again.\n");
      clearBuffer();
    } else {
      return num;
    }
  }
}
