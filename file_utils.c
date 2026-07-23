#include <stdio.h>
#include "file_utils.h"

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