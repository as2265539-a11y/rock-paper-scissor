#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int userChoice, computerChoice;
    int userScore = 0, computerScore = 0;
    int choice;

    // Initialize random number generator
    srand((unsigned int)time(NULL));

    printf("====================================\n");
    printf("      STONE PAPER SCISSORS GAME\n");
    printf("====================================\n");

    while (1)
    {
        printf("\n----------- MENU -----------\n");
        printf("1. Stone\n");
        printf("2. Paper\n");
        printf("3. Scissors\n");
        printf("4. Exit\n");
        printf("----------------------------\n");

        printf("Enter your choice: ");
        scanf_s("%d", &userChoice);

        // Exit the game
        if (userChoice == 4)
        {
            printf("\nExiting the game...\n");
            break;
        }

        // Validate user's choice
        if (userChoice < 1 || userChoice > 4)
        {
            printf("\nInvalid choice! Please enter 1, 2, 3, or 4.\n");
            continue;
        }

        // Generate computer choice randomly
        computerChoice = rand() % 3 + 1;

        // Display user's choice
        printf("\nYour choice: ");

        if (userChoice == 1)
        {
            printf("Stone");
        }
        else if (userChoice == 2)
        {
            printf("Paper");
        }
        else
        {
            printf("Scissors");
        }

        // Display computer's choice
        printf("\nComputer's choice: ");

        if (computerChoice == 1)
        {
            printf("Stone");
        }
        else if (computerChoice == 2)
        {
            printf("Paper");
        }
        else
        {
            printf("Scissors");
        }

        // Compare choices and decide the winner
        if (userChoice == computerChoice)
        {
            printf("\nResult: Draw!");
        }
        else if ((userChoice == 1 && computerChoice == 3) ||
                 (userChoice == 2 && computerChoice == 1) ||
                 (userChoice == 3 && computerChoice == 2))
        {
            printf("\nResult: User wins!");
            userScore++;
        }
        else
        {
            printf("\nResult: Computer wins!");
            computerScore++;
        }

        // Display current score
        printf("\n\nScore:");
        printf("\nUser     : %d", userScore);
        printf("\nComputer : %d\n", computerScore);

        // Ask whether the user wants another round
        printf("\nDo you want to continue?\n");
        printf("1. Yes\n");
        printf("2. No\n");
        printf("Enter your choice: ");
        scanf_s("%d", &choice);

        if (choice == 2)
        {
            break;
        }
        else if (choice != 1)
        {
            printf("\nInvalid choice. Returning to main menu.\n");
        }
    }

    // Final score
    printf("\n====================================\n");
    printf("           FINAL SCORE\n");
    printf("====================================\n");
    printf("User     : %d\n", userScore);
    printf("Computer : %d\n", computerScore);

    if (userScore > computerScore)
    {
        printf("Overall Winner: User\n");
    }
    else if (computerScore > userScore)
    {
        printf("Overall Winner: Computer\n");
    }
    else
    {
        printf("Overall Result: Draw\n");
    }

    printf("====================================\n");
    printf("Thank you for playing!\n");

    return 0;
}
