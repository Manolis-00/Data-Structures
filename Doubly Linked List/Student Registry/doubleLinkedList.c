#include "doubleLinkedList.h"

void initializeDoubleLinkedList(LIST_PTR *head)
{
    *head = NULL;
}

int chechEmptyDoubleLinkedList(LIST_PTR head)
{
    return head == NULL;
}

element returnNodeData(LIST_PTR pointerToNode)
{
    return pointerToNode->data;
}

int insertStartDoubleLinkedList(LIST_PTR *head, element input)
{
    LIST_PTR newNode;

    newNode = (LIST_NODE *)malloc(sizeof (LIST_NODE));
    if (!newNode)
    {
        printf("Problem with memory allocation");
        return FALSE;
    }
    newNode->data = input;                                                  //the data of the input are stored in the variable

    newNode->nextNode = *head;                                             //the newnode, now points to the same node with head
    newNode->previousNode = NULL;                                          //since we are the start of the list, before there is NULL
    *head = newNode;                                                       //head now points to newNode
    if(newNode->nextNode != NULL)                                           //checking that a next node exists
        newNode->nextNode->previousNode = newNode;                         //next nodes previous, now points to the newnode.
    return TRUE;
}

int insertAfterDoubleLinkedList(LIST_PTR previous, element input)
{
    LIST_PTR newNode;

    newNode = (LIST_NODE *)malloc(sizeof (LIST_NODE));
    if (!newNode)
    {
        printf("Problem with memory allocation");
        return FALSE;
    }
    newNode->data = input;

    newNode->nextNode = previous->nextNode;                             //newnode's next, points where previous node was pointing
    newNode->previousNode = previous;                                   //newnode's previous, points to the previous node
    previous->nextNode = newNode;                                       //previous's next, points to the new node

    if(newNode->nextNode != NULL)                                       //if newnode's next exists,
        newNode->nextNode->previousNode = newNode;

    return TRUE;
}

int deleteStartDoubleLinkedList(LIST_PTR *head, element *nodeToBeRemoved)
{
    LIST_PTR current;

    if(*head == NULL)
        return FALSE;

    current = *head;                                        //current points, to the first element of the list (element to be deleted)
    *nodeToBeRemoved = current->data;                       //we store the previous data, to the pointer so we can return it by reference

    (*head) = (*head)->nextNode;                            //head points to the node, that the node to be removed is pointing at
    if ((*head) != NULL)
        (*head)->previousNode = NULL;                       //the node after the node to be deleted, has it's previous showing to the node before the node to be deleted

    free(current);
    return TRUE;
}

int deleteAfterDoubleLInkedList(LIST_PTR previous, element *nodeToBeRemoved)
{
    LIST_PTR current;

    if (previous->nextNode == NULL)
        return FALSE;

    current = previous->nextNode;                                               //current points to the node that is to be removed (after previous)
    *nodeToBeRemoved = current->data;                                           //the data of the node that is going to be removed is stored to the variable so it can be returned to main

    previous->nextNode = current->nextNode;                                     //the previous node, is set to point to the node after the one that will be deleted

    if(current->nextNode != NULL)
        current->nextNode->previousNode = previous;                             //the after node, from the one that is going to be deleted, points, before the node that will be deleted

    free(current);
    return TRUE;
}

void printDoubleLinkedList(LIST_PTR head)
{
    LIST_PTR current;

    current = head;
    while (current != NULL)
    {
        printf("%d", current->data);
        current = current->nextNode;
    }
}

void destroyDoubleLinkedList(LIST_PTR *head)
{
    LIST_PTR ptr;

    while (*head != NULL)
    {
        ptr = *head;
        *head = (*head)->nextNode;
        free(ptr);
    }
}