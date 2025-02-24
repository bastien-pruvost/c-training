#include <stdio.h>
#include "calculation.h"

int doubleNumber(int number)
{
  return 2 * number;
}

void tripleNumber(int *numberPointer)
{
  *numberPointer *= 3;
}