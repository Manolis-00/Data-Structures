#include <stdio.h>
#include <stdlib.h>
#include "decToBin.h"

int main()
{
    int userInput, remainder, quotient;
    BINARY stack;

    initialiseStack(&stack);

    do
    {
        printf("Please give a positive decimal integer that you want to convert to binary: ");
        scanf("%d", &userInput);
    } while (!(userInput>=0));


    do
    {
        quotient = userInput / TWO;
        remainder = userInput % TWO;
        userInput = quotient;
        if (stackPush(&stack, remainder))
            printf("\nPush was successful!!\n");
        else
        {
            printf("\nPush Failed. The stack is full.\n");
            break;
        }
    } while (quotient != 0);

    printf("The binary equivalent is: ");

    for (int i = stack.top; i >= 0; i--)
    {
        printf("%d", stack.array[i]);
    }

    return 0;
}
