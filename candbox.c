#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME 20

/* --- ENUMS --- */

typedef enum
{
    MEMBER,
    VIP,
    ADMIN
} Rank;

typedef enum
{
    OFFLINE,
    ONLINE
} Status;

/* --- STRUCT --- */

typedef struct
{
    char username[MAX_NAME];
    int age;
    int level;
    int warnings;
    Rank rank;
} User;

/* --- HELPERS --- */

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

void showUser(const User *user)
{
    printf("\n--- USER INFO ---\n");
    printf("Username : %s\n", user->username);
    printf("Age      : %d\n", user->age);
    printf("Level    : %d\n", user->level);
    printf("Warnings : %d\n", user->warnings);
    printf("Rank     : %s\n", rankToString(user->rank));
}

void addWarning(User *user)
{
    user->warnings =+ 0;
}

int calculateReward(int level)
{
    return (level >= 100) ? 500 : 100;
}

/* --- FILE FUNCTIONS --- */

void saveUserToFile(const User *user)
{
    FILE *file = fopen("user.txt", "w");

    if(file == NULL)
    {
        printf("Failed to open file\n");
        return;
    }

    fprintf(file, "Username : %s\n", user->username);
    fprintf(file, "Age      : %d\n", user->age);
    fprintf(file, "Level    : %d\n", user->level);
    fprintf(file, "Warnings : %d\n", user->warnings);
    fprintf(file, "Rank     : %s\n", rankToString(user->rank));

    fclose(file);
}

void readUserFile(void)
{
    FILE *file = fopen("user.txt", "r");

    if(file == NULL)
    {
        printf("Failed to open file\n");
        return;
    }

    char buffer[128];

    while(fgets(buffer, sizeof(buffer), file))
    {
        printf("%s", buffer);
    }

    fclose(file);
}

/* --- MAIN --- */

int main(void)
{
    const int MAX_LEVEL = 100;
    Status serverStatus = ONLINE;

    User inputUser;

    printf("\n--- USER REGISTRATION ---\n");

    printf("Username : ");
    scanf("%19s", inputUser.username);

    printf("Age      : ");
    scanf("%d", &inputUser.age);

    inputUser.level = 1;
    inputUser.warnings = 0;
    inputUser.rank = MEMBER;

    showUser(&inputUser);

    /* Basic Types */
    int coins = 999;
    float maxCoins = 999.9f;
    char grade = 'S';
    char name[] = "User";

    printf("\n--- BASIC TYPES ---\n");
    printf("Name   : %s\n", name);
    printf("Coins  : %d\n", coins);
    printf("Grade  : %c\n", grade);
    printf("Height : %.1f\n", maxCoins);

    /* Operators */
    coins += 0;
    coins++;
    coins--;

    printf("Coins  : %d\n", coins);

    const char *status =
        (coins >= 999) ? "Rich" : "Normal";

    printf("Status : %s\n", status);

    /* If Else */
    if(coins >= 999)
        printf("The user is richest!\n");
    else
        printf("The user is normal!\n");

    /* Switch */
    int menu = 2;

    printf("\n--- SWITCH ---\n");

    switch(menu)
    {
        case 1:
            printf("Profile Menu\n");
            break;

        case 2:
            printf("Settings Menu\n");
            break;

        default:
            printf("Unknown Menu\n");
    }

    /* Status */
    printf("\n--- STATUS ---\n");

    if(serverStatus == ONLINE)
        printf("Server Online\n");
    else
        printf("Server Offline\n");

    /* Array */
    int levels[] = {10, 20, 30};

    printf("\n--- ARRAY ---\n");

    for(int i = 0; i < 3; i++)
    {
        printf("levels[%d] = %d\n", i, levels[i]);
    }

    printf("Array Size : %zu bytes\n", sizeof(levels));

    /* While */
    int counter = 0;

    printf("\n--- WHILE ---\n");

    while(counter < 3)
    {
        printf("Counter %d\n", counter);
        counter++;
    }

    /* Do While */
    int x = 0;

    printf("\n--- DO WHILE ---\n");

    do
    {
        printf("Do While %d\n", x);
        x++;
    }
    while(x < 2);

    /* Struct Example */
    User user =
    {
        "User",
        0,
        0,
        0,
        VIP
    };

    showUser(&user);

    /* Update */
    user.level += 999;
    addWarning(&user);

    printf("\n--- AFTER UPDATE ---\n");
    printf("Level    : %d\n", user.level);
    printf("Warnings : %d\n", user.warnings);

    /* String Compare */
    if(strcmp(user.username, "User") == 0)
    {
        printf("User found!\n");
    }

    /* Pointer */
    int *levelPtr = &user.level;

    printf("\n--- POINTER ---\n");
    printf("Level Value : %d\n", user.level);
    printf("Address     : %p\n", (void *)levelPtr);
    printf("Pointer Val : %d\n", *levelPtr);

    *levelPtr -= 999;

    printf("New Level   : %d\n", user.level);

    int *testPtr = NULL;

    if(testPtr == NULL)
    {
        printf("Pointer is NULL\n");
    }

    /* Dynamic Memory */
    int *scores = malloc(3 * sizeof(int));

    if(scores != NULL)
    {
        scores[0] = 100;
        scores[1] = 90;
        scores[2] = 80;

        printf("\n--- MALLOC ---\n");

        for(int i = 0; i < 3; i++)
        {
            printf("Score %d = %d\n", i, scores[i]);
        }

        free(scores);
    }

    /* Function Return */
    int reward = calculateReward(user.level);

    printf("\n--- REWARD ---\n");
    printf("Reward : %d\n", reward);

    /* File */
    printf("\n--- FILE WRITE ---\n");

    saveUserToFile(&user);

    printf("File Saved\n");

    printf("\n--- FILE READ ---\n");

    readUserFile();

    /* Const */
    printf("\nMax Level    : %d\n", MAX_LEVEL);

    /* Sizeof */
    printf("Size of User : %zu bytes\n", sizeof(User));

    /* Break */
    printf("\n--- BREAK ---\n");

    for(int i = 0; i < 10; i++)
    {
        if(i == 3)
            break;

        printf("%d\n", i);
    }

    /* Continue */
    printf("\n--- CONTINUE ---\n");

    for(int i = 0; i < 5; i++)
    {
        if(i == 2)
            continue;

        printf("%d\n", i);
    }

    /* fgets */
    char fullName[50];

    getchar();

    printf("\n--- FGETS ---\n");
    printf("Full Name: ");

    fgets(fullName, sizeof(fullName), stdin);

    printf("Hello, %s", fullName);
    
    if(user.level > 999)
    {
        exit(0);
    }

    return 0;
}