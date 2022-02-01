#include "polish.h"

void initialiseStack(POLISH *stack)
{
    stack->top=-1;
}

int checkEmpty(POLISH stack)
{
    return stack.top==-1;
}

int checkFull(POLISH stack)
{
    return stack.top==STACK_SIZE-1;
}

int stackPush(POLISH *stack, element digit)
{
    if (checkFull(*stack))
        return FALSE;
    else
    {
        stack->top++;
        stack->array[stack->top]=digit;
    }
}

int stackPop(POLISH *stack, element *digit)
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
