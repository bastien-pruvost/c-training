#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    string name;
    string number;
} person;

int main (void)
{
    person people[3];

    people[0].name = "David";
    people[0].number = "+1-617-495-1000";

    people[1].name = "John";
    people[1].number = "+1-617-738-8475";

    people[2].name = "Yuliia";
    people[2].number = "+1-617-024-2954";

    string name = get_string("Name: ");

    for (int i = 0; i < 3; i++)
    {
        if (strcmp(people[i].name, name) == 0)
        {
            printf("Found %s's number: %s \n", people[i].name, people[i].number);
            return 0;
        }
    }
    printf("Not found!\n");
    return 1;
}
