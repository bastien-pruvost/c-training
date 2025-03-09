#ifndef USER_H
#define USER_H

typedef enum UserRole UserRole;
enum UserRole { GUEST, USER, ADMIN };

typedef struct User User;
struct User {
  int id;
  char firstname[255];
  char lastname[255];
  int age;
  UserRole role;
};

void assignValuesToUser(User *user, int id);

#endif
