#include <stdio.h>
#include <stdlib.h>
#include "polish.h"

int main()
{
    char userInput;
    double number, firstPoped, secondPoped;
    POLISH stack;

    printf("Please give a mathematical formula with Polish notation: ");

    userInput=getchar();
    initialiseStack(&stack);

    while (userInput != '\n')
    {
        if (userInput >= '0' && userInput <= '9')
        {
            number = userInput - '0'; //me tin voitheia toy ASCII
            stackPush(&stack, number);
        }
        else //telestis
        {
            stackPop(&stack, &firstPoped);
            stackPop(&stack, &secondPoped);

            switch (userInput)
            {
                case '+':
                    number = firstPoped + secondPoped;
                    break;
                case '-':
                    number = secondPoped - firstPoped;
                    break;
                case '*':
                    number = firstPoped * secondPoped;
                    break;
                case '/':
                    number = secondPoped / firstPoped;
                    break;
            }
            stackPush(&stack, number);
        }
        userInput=getchar();
    }

    stackPop(&stack, &number);
    printf("\nThe result is: %.3f", number);

    return 0;
}
