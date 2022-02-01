#include "decToBin.h"

void initialiseStack(BINARY *stack)
{
    stack->top=-1;
}

int checkEmpty(BINARY stack)
{
    return stack.top==-1;
}

int checkFull(BINARY stack)
{
    return stack.top==STACK_SIZE-1;
}

int stackPush(BINARY *stack, element digit)
{
    if (checkFull(*stack))
        return FALSE;
    else
    {
        stack->top++;
        stack->array[stack->top]=digit;
    }
}

int stackPop(BINARY *stack, element *digit)
{
    if(checkEmpty(*stack))
        return FALSE;
    else
    {
        *digit = stack -> array[stack->top];
        stack->top--;
        return TRUE;
    }
}
