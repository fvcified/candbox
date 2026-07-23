#ifndef USER_H
#define USER_H

#define MAX_NAME 20

typedef enum
{
    MEMBER,
    VIP,
    ADMIN
} Rank;

typedef struct
{
    char username[MAX_NAME];
    int age;
    int level;
    int warnings;
    Rank rank;
} User;

void registerUser(User *user);
void showUser(const User *user);
const char *rankToString(Rank rank);
int calculateReward(int level);
void addWarning(User *user);

#endif