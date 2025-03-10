#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

#define LENGTH 4

typedef struct node
{
    int number;
    struct node *next;
} node;

int main(void)
{
    node *list = NULL;

    for (int i = 0; i < LENGTH; i++)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            // TODO: free any memory already malloc'd
            return 1;
        }

        // Ask user to set a value for this n node
        n->number = get_int("Number: "); // `n->number` is a shortcut for `(*n).number`

        // // Method 1 : LIFO (Last In First Out) -> Simple but list is reversed
        // // Set the current node 'next' = 'list'
        // n->next = list;
        // // Set 'list' = 'current node'
        // list = n;

        // Method 2 : FIFO (First In First Out) -> More complicated but list is not reversed
        // Set the current node 'next' = NULL
        n->next = NULL;
        // If list is empty (the current node is the first)
        if (list == NULL)
        {
            // Just append the current node
            list = n;
        }

        // // If i want to append and sort the list in same time
        // else if (n->number < list->number)
        // {
        //     n->next = list;
        //     list = n;
        // }

        // Else if list is not empty (we need to put the current node at the end)
        else
        {
            // For each existing node in the list
            for (node *ptr = list; ptr != NULL; ptr = ptr->next)
            {
                // If we are at end of list (next existing node is NULL)
                if (ptr->next == NULL)
                {
                    // Append the current node to the existing node 'next' (the last)
                    ptr->next = n;
                    break;
                }

                // // Also if i want to append but sort the list in same time
                // if (n->number < ptr->next->number)
                // {
                //     n->next = ptr->next;
                //     ptr->next = n;
                //     break:
                // }
            }
        }
    }

    for (node *ptr = list; ptr != NULL; ptr = ptr->next)
    {
        printf("%d\n", ptr->number);
    }

    node *ptr = list;
    while (ptr != NULL)
    {
        node *next = ptr->next;
        free(ptr);
        ptr = next;
    }

    return 0;
}
