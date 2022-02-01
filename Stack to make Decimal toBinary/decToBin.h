#ifndef EFARMOGI_3_DECTOBIN_H
#define EFARMOGI_3_DECTOBIN_H

#define STACK_SIZE 50
#define TRUE 1
#define TWO 2
#define FALSE 0

typedef int element;

struct stack
{
    element array[STACK_SIZE];
    int top;
};

typedef struct stack BINARY;

void initialiseStack(BINARY *stack);
int checkEmpty(BINARY stack);
int checkFull(BINARY stack);
int stackPush(BINARY *stack, element digit);
int stackPop(BINARY *stack, element *digit);

#endif //EFARMOGI_3_DECTOBIN_H
