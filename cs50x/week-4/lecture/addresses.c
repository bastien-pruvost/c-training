#include <stdio.h>

int main(void)
{
    int n = 50;
    int *p = &n;

    // Print the address of n
    printf("%p\n", &n);

    // Print the value of n
    printf("%d\n", n);

    // Print the pointer p (address of n)
    printf("%p\n", p);

    // Print the value of the target of p (value of n)
    printf("%d\n", *p);

    // Print the address of p (useless)
    printf("%p\n", &p);

}
