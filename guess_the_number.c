#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define THRESHOLD 5

void SetRange(int *min, int *max);
int GetRandomNumber(int min, int max);
int MakeGuess(int min, int max);

void SetRange(int *min, int *max)
{
    char buffer[256];
    int scan_result = 0;
    
    do
    {
        printf("Give the minimum number: ");
        fgets(buffer, sizeof(buffer), stdin);
        scan_result = sscanf(buffer, "%d", min);

        if (scan_result != 1)
        {
            printf("Invalid input. Please enter an integer.\n");
        }

    } while (scan_result != 1);
    
    scan_result = 0;
    
    do
    {
        printf("Give the maximum number: ");
        fgets(buffer, sizeof(buffer), stdin);
        scan_result = sscanf(buffer, "%d", max);

        if (scan_result != 1)
        {
            printf("Invalid input. Please enter an integer.\n");
        }

    } while (scan_result != 1);
}

int GetRandomNumber(int min, int max)
{
    int target = (rand() % (max - min + 1)) + min;
    return target;
}

int MakeGuess(int min, int max)
{
    int num;
    char buffer[256];
    int scan_result = 0;

    do
    {
        printf("Give a number between %d and %d: ", min, max);
        fgets(buffer, sizeof(buffer), stdin);
        
        scan_result = sscanf(buffer, "%d", &num);

        if (scan_result != 1) 
        {
            printf("Invalid input. Please enter an integer.\n");
        }
        
    } while (scan_result != 1);

    return num;
}

int main()
{
    
    int guesses = 0, target, min, max, guess, found = 0;
    
    SetRange(&min, &max);
    srand(time(NULL));
    target = GetRandomNumber(min, max);
    
    while (guesses++ < THRESHOLD)
    {
        guess = MakeGuess(min, max);

        if (guess > target)
        {            
            printf("Your guess is too high! Try again: you have %d guesses remaining.\n", THRESHOLD - guesses);
        }
            
        else if (guess < target)
        {
            printf("Your guess is too low! Try again: you have %d guesses remaining.\n", THRESHOLD - guesses);
        }
            
        else
        {
            printf("You found the number (%d) after %d guesses!\n", target, guesses);
            found = 1;
            break;
        }
    }
    
    if (found == 0)
    {
        printf("Sorry, you ran out of guesses. The number was %d.\n", target);
    }

    return 0;
}