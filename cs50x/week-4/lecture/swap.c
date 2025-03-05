#include <stdio.h>

void swap(int *a, int *b);

int main(void)
{
    int x = 1;
    int y = 2;

    printf("x = %d ; y = %d\n", x, y);
    swap(&x, &y);
    printf("x = %d ; y = %d\n", x, y);
}

void swap(int *a, int *b)
{
    int tmp_a = *a;
    *a = *b;
    *b = tmp_a;
}
