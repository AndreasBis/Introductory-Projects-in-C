#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define ROCK 1
#define PAPER 2
#define SCISSORS 3

int UserChoice(void);
int ComputerChoice(void);
void Play(void);
void printChoiceName(int choice);

int UserChoice(void)
{
    int choice;
    int scan_result = 0;
    char buffer[32];

    printf("Choose an option: \n");
    printf("1. Rock\n");
    printf("2. Paper\n");
    printf("3. Scissors\n");
    printf("Your choice: ");

    do
    {
        fgets(buffer, sizeof(buffer), stdin);
        scan_result = sscanf(buffer, "%d", &choice);

        if (scan_result != 1)
        {
            printf("Enter only an integer (1, 2 or 3)! Try again.\n");
            printf("Your choice: ");
        }
        else if (choice < ROCK || choice > SCISSORS)
        {
            printf("Invalid choice. Enter 1, 2, or 3. Try again.\n");
            printf("Your choice: ");
            scan_result = 0;
        }
        
    } while (scan_result != 1);    

    return choice;
}

int ComputerChoice(void)
{
    int choice = rand() % 3 + 1;    
    return choice;
}

void printChoiceName(int choice)
{
    switch(choice)
    {
        case ROCK:
            printf("Rock");
            break;
        case PAPER:
            printf("Paper");
            break;
        case SCISSORS:
            printf("Scissors");
            break;
    }
}

void Play(void)
{
    int user_choice = UserChoice();
    int computer_choice = ComputerChoice();

    printf("\n");
    printf("You chose: ");
    printChoiceName(user_choice);
    printf("\n");
    
    printf("Computer chose: ");
    printChoiceName(computer_choice);
    printf("\n\n");

    if (user_choice == computer_choice)
    {
        printf("It's a Tie!\n");
    }
    else if (
        (user_choice == ROCK && computer_choice == SCISSORS) ||
        (user_choice == PAPER && computer_choice == ROCK) ||
        (user_choice == SCISSORS && computer_choice == PAPER)
    )
    {
        printf("You Win!\n");
    }
    else
    {
        printf("You Lose!\n");
    }
}

int main(void)
{
    srand(time(NULL));

    char play_again;
    char buffer[32];
    int scan_result = 0;

    do
    {
        Play();

        do
        {
            printf("\nDo you want to play again (y/n)? ");
            fgets(buffer, sizeof(buffer), stdin);
            scan_result = sscanf(buffer, "%c", &play_again);

            if (scan_result != 1)
            {
                printf("Invalid input. Try again.\n");
            }
            else
            {
                play_again = tolower(play_again);
                if (play_again != 'y' && play_again != 'n')
                {
                    printf("Enter only y or n. Try again.\n");
                    scan_result = 0; 
                }
            }

        } while (scan_result != 1);
        
        printf("\n");
        
    } while (play_again == 'y');
    
    printf("Thanks for playing!\n");
    
    return 0;
}
