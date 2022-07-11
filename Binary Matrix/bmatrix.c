//KingOfMongeese
//July 7, 2022
//Binary Matrix
//Description: User enters a number and then we print out a 3x3 matric representing the binary value of the number. 
//H = 0; T = 1;

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void getString(char *buffer, int buffersize);
void decToBin(int dec, int *bin);

int main(void)
{   
    //gather input
    char buffer[32]; 
    int numberInBin[] = {0,0,0,0,0,0,0,0,0};
    printf("Enter a number between 0 and 511\n>");
    getString(buffer, 32);
    int number = strtol(buffer, NULL, 10);
    while (number > 511 || number < 0)
    {
        printf("Invalid input.\n");
        printf("Enter a new number that is between 0 and 511.\n>");
        getString(buffer, 32);
        number = strtol(buffer, NULL, 10);

    }

    decToBin(number, numberInBin);
    printf("\n");

    //printing out the matrix
    for (int i = 0, c = 0; i < 9; i++)
    {
        char letter = 'H';
        if (numberInBin[i] == 1)
        {
            letter = 'T';
        }

        printf("%c ", letter);
        
        if (++c % 3 == 0)
        {
            printf("\n");
        }
    }
    printf("\n");

    return 0;

}

void getString(char *buffer, int buffersize)
{
    fgets(buffer, buffersize, stdin);
    if (buffer[strlen(buffer) - 1] != '\n')
    {
        //flush in buffer
        int b;
        while (b = getchar() != '\n' && b != EOF){}
    }
    
}

void decToBin(int dec, int *bin)
{   
    //converts the given decimnal number into an array of size containing the binary value
    int i = 0;
    int temp[] = {0,0,0,0,0,0,0,0,0};
    while (dec != 0)
    {
        if (i < 10)
        {
        temp[i] = dec % 2;
        dec /= 2;
        }
        i++;
        
    }

    for (int i = 8, j = 0; i > -1; j++, i--)
    {
        *(bin + j) = temp[i];
    }
    

}