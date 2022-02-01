#include "stack.h"

void ST_init(STACK *s)
{
    s->top=-1;             //arxikopoiei tin stoiva ws adeia
}

int ST_empty(STACK s)
{
    return s.top==-1;
}

int ST_full(STACK s)
{
    return s.top==STACK_SIZE-1;
}

int ST_push(STACK *s, element x)
{
    if (ST_full(*s))
    {
        return FALSE;
    }
    else
    {
        s->top++;
        s->array[s->top]=x;
        return TRUE;
    }
}

int ST_pop(STACK *s, element *x)
{
    if(ST_empty(*s))
    {
        return FALSE;
    }
    else
    {
        *x=s->array[s->top];
        s->top--;
        return TRUE;
    }
}