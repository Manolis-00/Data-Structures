#ifndef THEORIA1_LIST_H
#define THEORIA1_LIST_H

#include <stddef.h>             //or define NULL 0
#include <malloc.h>
#include <string.h>

#define FALSE 0
#define TRUE 1

struct ELEMENT
{
    char name[80];
    int grade;
};

typedef struct ELEMENT element;

struct node
{
    element data;
    struct node *nextNodePointer;          //pointer to nextNodePointer node
};

typedef struct node LIST_NODE;  //node
typedef struct node *LIST_PTR;  //pointer to the node

void listInitialization(LIST_PTR *head);
int checkEmpty(LIST_PTR head);
element nodeData(LIST_PTR node);
int insertAtStart(LIST_PTR *head, element newNodeData);
int insertInBetween(LIST_PTR previousNode, element newNodeData);
int deleteAtStart(LIST_PTR *head, element *newNodeData);
int deleteAfter(LIST_PTR previousNode, element *nodeToBeDeleted);
void destroyList(LIST_PTR *head);
void printList(LIST_PTR head);

//Secondary functions
int insert(LIST_PTR *head, element newNode);
int delete(LIST_PTR *head, char *toBeDeleted);
double average(LIST_PTR head);
int successful(LIST_PTR head);

#endif //THEORIA1_LIST_H
