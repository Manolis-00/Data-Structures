#ifndef EFARMOGI_4_POLISH_H
#define EFARMOGI_4_POLISH_H

#define STACK_SIZE 20
#define TRUE 1
#define FALSE 0

typedef double element;

struct stack
{
    element array[STACK_SIZE];
    int top;
};

typedef struct stack POLISH;

void initialiseStack(POLISH *stack);
int checkEmpty(POLISH stack);
int checkFull(POLISH stack);
int stackPush(POLISH *stack, element digit);
int stackPop(POLISH *stack, element *digit);

#endif //EFARMOGI_4_POLISH_H
