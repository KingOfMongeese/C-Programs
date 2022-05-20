#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(void)
{
    int min, max, count;

    //char arrays used to take input
    char iMin[8], iMax[8], iCount[8];
    
    printf("This will generate numbers with a specified range.\nEnter the min>");
    //reads from input buffer to iMin
    //only takes the size of iMin (8) bytes
    //However this leaves the input buffer full if input is more than 8 bytes
    fgets(iMin, sizeof(iMin), stdin);

    if (iMin[strlen(iMin) - 1] != '\n')
    {
        //If the data > our buffer for iMin the the last char in the string will not be a new line
        //This will clear the buffer
        while ((getchar()) != '\n');
    }

    printf("Enter the max>");
    fgets(iMax, sizeof(iMax), stdin);
    if (iMax[strlen(iMax) - 1] != '\n')
    {
        while ((getchar()) != '\n');
    }

    printf("Enter the count>");
    fgets(iCount, sizeof(iCount), stdin);
    if (iCount[strlen(iCount) - 1] != '\n')
    {
        while ((getchar()) != '\n');
    }

    min = strtol(iMin, NULL, 10);
    max = strtol(iMax, NULL, 10);
    count = strtol(iCount, NULL, 10);
    int bound = max - min + 1;

    srand(time(0));
    printf("\n");

    for (int i = 0; i < count; i++)
    {
        int num = (rand() % bound) + min;
        printf("%d ", num);
    }

    printf("\n\nGenerated %d numbers from %d to %d", count, min, max);

}