#include "list.h"

void listInitialization(LIST_PTR *head)
{
    *head = NULL;                      //by reference
}

int checkEmpty(LIST_PTR head)
{
    return head == NULL;              //checks if head is empty and returns 1 or 0
}

element nodeData(LIST_PTR node)
{
    return node->data;               //returns data segment of the given node
}

int insertAtStart(LIST_PTR *head, element newNodeData)    //*head = NULL / = someValue
{
    LIST_PTR newNode;

    newNode = (LIST_NODE *)malloc(sizeof (LIST_NODE));   //binding of the necessary memory to store the new node
    if (!newNode)
    {
        printf("Unable to bind necessary memory\n");    //error message for malloc
        return FALSE;
    }
    newNode->data = newNodeData;                                //assign the data given as input to the node's data segment middleStep1

    newNode->nextNodePointer = *head;                        //assign the address of the next node, to the new node so it points there middleStep2
    *head = newNode;                                         //now head changes,and points to newnode

    return TRUE;
}

int insertInBetween(LIST_PTR previousNode, element newNodeData)
{
    LIST_PTR newNode;

    newNode = malloc(sizeof(LIST_NODE));
    if (!newNode)
    {
        printf("Unable to bind necessary memory\n");
        return FALSE;
    }
    newNode->data = newNodeData;                               //assign the data given as input to the node's data segment middleStep1

    newNode->nextNodePointer = previousNode->nextNodePointer;       //assign the address of the next node, to the new node so it points there middleStep2
    previousNode->nextNodePointer = newNode;                        //now previousNode changes,and points to newnode

    return TRUE;
}

int deleteAtStart(LIST_PTR *head, element *newNodeData)
{
    LIST_PTR current;                                   //temporary pointer

    if (*head == NULL)                                  //check for empty list. If true break
        return FALSE;

    current = *head;                                    //temporary pointer, keeps the mem position of first node
    *newNodeData = current->data;                          //newNodeData has the data stored in the node that is going to be deleted

    (*head) = (*head)->nextNodePointer;                 //point to the node after the one to be deleted
    free(current);

    return TRUE;
}

int deleteAfter(LIST_PTR previousNode, element *nodeToBeDeleted)
{
    LIST_PTR currentNode;

    if (previousNode->nextNodePointer == NULL)                      //if list is empty
        return FALSE;

    currentNode = previousNode->nextNodePointer;                    //temporary pointer, keeps the mem position of the node that is pointed by the previous
    *nodeToBeDeleted = currentNode->data;                           //data of the next node is stored to the node to be inserted

    previousNode->nextNodePointer = currentNode->nextNodePointer;   //previous node, points to the point after the nodetobedeleted
    free(currentNode);

    return TRUE;
}

void destroyList(LIST_PTR *head)
{
    LIST_PTR ptr;

    while (*head != NULL)
    {
        ptr = *head;
        *head = (*head)->nextNodePointer;                          //head goes one node later
        free(ptr);
    }
}

void printList(LIST_PTR head) {                                 //SOS διαπεραση λιστας
    LIST_PTR current;

    current = head;
    while (current != NULL)
    {
        printf("(%s, %d)-->\n", current->data.name, current->data.grade);
        current = current->nextNodePointer;                     //next node
    }
    printf(".");
}

//secondary functions
int insert(LIST_PTR *head, element newNode)
{
    LIST_PTR current, previous;

    if (*head ==NULL)
        return insertAtStart(head, newNode);
    else
    {
        current = *head;
        previous = current;

        while (current != NULL)
        {
            if (strcmp(current->data.name, newNode.name) >0)
            {
                if (current == *head)
                    return insertAtStart(head, newNode);
                else
                    return insertInBetween(previous,newNode);
            }
            previous = current;
            current = current->nextNodePointer;
        }

        return insertInBetween(previous, newNode);
    }
}

int delete(LIST_PTR *head, char *toBeDeleted)
{
    LIST_PTR current, previous;
    element temporary;

    if (*head==NULL)
        return FALSE;

    current = *head;
    previous=current;
    while(current!=NULL)
    {

        if (strcmp(current->data.name,toBeDeleted)==0)
        {
            if (current==*head)
                return deleteAtStart(head, &temporary);
            else
                return deleteAfter(previous, &temporary);
        }

        previous = current;
        current=current->nextNodePointer;
    }

    return FALSE;
}

double average(LIST_PTR head)
{
    LIST_PTR current;
    int sum = 0;
    int counter = 0;
    current = head;

    while (current != NULL)
    {
        sum += current->data.grade;
        current = current->nextNodePointer;
        counter++;
    }

    return sum /(double)counter;
}

int successful(LIST_PTR head)
{
    LIST_PTR current;
    int counter = 0;

    current = head;

    while (current != NULL)
    {
        if (current->data.grade >= 5)
            counter++;
        current = current->nextNodePointer;
    }

    return counter;
}