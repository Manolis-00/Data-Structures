#ifndef THEORIA_1_STACK_H
#define THEORIA_1_STACK_H

#define STACK_SIZE 10
#define TRUE 1
#define FALSE 0

typedef int element; //i stoiva dexetai akeraious

struct stack
{
    element array[STACK_SIZE];
    int top;
};

typedef struct stack STACK;

void ST_init(STACK *s);                     //afou to s epireazei ta dedomena tis stoivas mpainei ws pointer
int ST_empty(STACK s);                      // den xreiazetai pointer afoy ta stoixeia tis stoivas den metavalontai
int ST_full(STACK s);
int ST_push(STACK *s, element x);
int ST_pop(STACK *s, element *x);

#endif //THEORIA_1_STACK_H