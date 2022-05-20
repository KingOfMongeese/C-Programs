#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int die1, die2, count, sum, bound;
    char iCount[12];

    //rand seed
    srand(time(0));

    printf("Enter the Number of times to roll the 2d6\n>");

    fgets(iCount, sizeof(iCount), stdin);
    if (iCount[strlen(iCount) - 1] != '\n')
    {
        //clear the in buffer
        int b;
        while( (b = getchar()) != '\n' && b != EOF){}
    }

    count = strtol(iCount, NULL, 10);
    bound = 6 - 1 + 1;

    for (int i = 0; i < count; i++)
    {
        die1 = (rand() % bound) + 1;
        die2 = (rand() % bound) + 1;
        sum = die1 + die2;
        printf("%d + %d = %d\n", die1, die2, sum);
    }

    return 0;
}