#include <stdio.h>
#include <stdlib.h>

#include "demos.h"

void demoInput(void)
{
    char fullName[50];

    printf("\n--- FGETS ---\n");
    printf("Full Name: ");

    if (fgets(fullName, sizeof(fullName), stdin) != NULL)
    {
        printf("Hello, %s", fullName);
    }
}

void demoBasicTypes(void)
{
    int coins = 999;
    float maxCoins = 999.9f;
    char grade = 'S';
    char name[] = "User";

    printf("\n--- BASIC TYPES ---\n");

    printf("Name      : %s\n", name);
    printf("Coins     : %d\n", coins);
    printf("Grade     : %c\n", grade);
    printf("Max Coins : %.1f\n", maxCoins);
}

void demoArrays(void)
{
    int levels[] = {10, 20, 30};

    printf("\n--- ARRAY ---\n");

    for(int i = 0; i < 3; i++)
    {
        printf("levels[%d] = %d\n", i, levels[i]);
    }

    printf("Array Size : %zu bytes\n", sizeof(levels));
}

void demoLoops(void)
{
    int counter = 0;

    printf("\n--- WHILE ---\n");

    while(counter < 3)
    {
        printf("Counter %d\n", counter);
        counter++;
    }

    int x = 0;

    printf("\n--- DO WHILE ---\n");

    do
    {
        printf("Do While %d\n", x);
        x++;
    }
    while(x < 2);
}

void demoPointers(User *user)
{
    int *levelPtr = &user->level;

    printf("\n--- POINTER ---\n");

    printf("Level Value : %d\n", user->level);
    printf("Address     : %p\n", (void *)levelPtr);
    printf("Pointer Val : %d\n", *levelPtr);

    *levelPtr += 50;

    printf("New Level   : %d\n", user->level);

    int *testPtr = NULL;

    if(testPtr == NULL)
    {
        printf("Pointer is NULL\n");
    }
}

void demoDynamicMemory(void)
{
    int *scores = malloc(3 * sizeof(int));

    if(scores == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

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