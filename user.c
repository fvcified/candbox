#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "user.h"

void registerUser(User *user)
{
    char buffer[32];

    printf("\n--- USER REGISTRATION ---\n");

    printf("Username : ");
    fgets(user->username, sizeof(user->username), stdin);

    user->username[strcspn(user->username, "\n")] = '\0';

    printf("Age      : ");
    fgets(buffer, sizeof(buffer), stdin);

    user->age = atoi(buffer);

    user->level = 1;
    user->warnings = 0;
    user->rank = MEMBER;
}

void showUser(const User *user)
{
    printf("\n--- USER INFO ---\n");
    printf("Username : %s\n", user->username);
    printf("Age      : %d\n", user->age);
    printf("Level    : %d\n", user->level);
    printf("Warnings : %d\n", user->warnings);
    printf("Rank     : %s\n", rankToString(user->rank));
}

const char *rankToString(Rank rank)
{
    switch(rank)
    {
        case MEMBER: return "Member";
        case VIP:    return "VIP";
        case ADMIN:  return "Admin";
        default:     return "Unknown";
    }
}

int calculateReward(int level)
{
    return (level >= 100) ? 500 : 100;
}

void addWarning(User *user)
{
    user->warnings++;
}