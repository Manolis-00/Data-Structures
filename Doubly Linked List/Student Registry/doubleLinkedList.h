#ifndef DOUBLE_LINKED_LIST_DOUBLELINKEDLIST_H
#define DOUBLE_LINKED_LIST_DOUBLELINKEDLIST_H

#include <stddef.h>
#include <malloc.h>

#define FALSE 0
#define TRUE 1

typedef int element;

struct node
{
    element data;
    struct node *nextNode;
    struct node *previousNode;
};

typedef struct node LIST_NODE;                              //list node
typedef struct node *LIST_PTR;                              //node pointer

void initializeDoubleLinkedList(LIST_PTR *head);
int chechEmptyDoubleLinkedList(LIST_PTR head);
element returnNodeData(LIST_PTR pointerToNode);
int insertStartDoubleLinkedList(LIST_PTR *head, element input);
int insertAfterDoubleLinkedList(LIST_PTR previous, element input);
int deleteStartDoubleLinkedList(LIST_PTR *head, element *nodeToBeRemoved);
int deleteAfterDoubleLInkedList(LIST_PTR previous, element *nodeToBeRemoved);
void printDoubleLinkedList(LIST_PTR head);
void destroyDoubleLinkedList(LIST_PTR *head);

#endif //DOUBLE_LINKED_LIST_DOUBLELINKEDLIST_H
