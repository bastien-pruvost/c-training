#include <stdio.h>

#include "user.h"

void assignValuesToUser(User *user, int id)
{
    printf("USER %d:\n", id);
    // (*user).id = id;
    user->id = id; // user->id is a shortcut for (*user).id
    printf("Firstname: ");
    scanf("%255s", (*user).firstname);
    printf("Lastname: ");
    scanf("%255s", user->lastname); // user->lastname is a shortcut for (*user).lastname
    printf("Age: ");
    // scanf("%d", &(*user).age);
    scanf("%d", &user->age); // &user->age is a shortcut for &(*user).age

    char is_admin[4] = "n";
    printf("Is admin (y/n): ");
    scanf("%3s", is_admin);

    if (is_admin[0] == 'y')
    {
        user->role = ADMIN;
    }
    else
    {
        user->role = USER;
    }

    printf("\n");
}