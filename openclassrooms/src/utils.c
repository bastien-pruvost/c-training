#include <stdio.h>

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
