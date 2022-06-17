//KingOfMongeese
//June 17, 2022
//Plays the Game: Craps


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

//Protoytpes
int rollD6(void);
void playGame(void);
void continueGame(int point);


int main(void)
{
    srand(time(0));

    playGame();

    while (1)
    {
        printf("Do you want to play again?(Y/n):\n>");
        char cont[4];
        fgets(cont, sizeof(cont), stdin);
        if (cont[strlen(cont) - 1] != '\n')
        {
            int b;
            while (b = getchar() != '\n' && b != EOF){}
        }

        if (tolower(cont[0]) == 'y')
        {
            printf("----------------------------------\n\n");
            playGame();
        }
        else
        {
            printf("Goodbye\n");
            break;
        }
    }
    
    return 0;
}

int rollD6(void)
{
    //rolls the dice
    int roll = (rand() % 6) + 1 ;
    return roll;
}

void playGame(void)
{
    //plays the game
    int die1 = rollD6();
    int die2 = rollD6();
    int sum = die1 + die2;
    printf("%d + %d = %d\n", die1, die2, sum);

    switch (sum)
    {
        case 2:
        case 3:
        case 12: printf("You lost :(\n"); break;
        case 7:
        case 11: printf("You win :)\n"); break;

        default: printf("Point is %d\n", sum); continueGame(sum); break;
    }
}

void continueGame(int point)
{
    //controls the second phase of the game.
    while(1)
    {
        int die1 = rollD6();
        int die2 = rollD6();
        int sum = die1 + die2;
        printf("%d + %d = %d\n", die1, die2, sum);

        if (sum == point)
        {
            printf("You win :)\n");
            break;
        }
        else if (sum == 7)
        {
            printf("You lost :(\n");
            break;
        }
    }
}