#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main() {
    LIST_PTR list;
    element student;
    int userInput;

    listInitialization(&list);

    while (1) {
        printf("Menu\n");
        printf("========\n");
        printf("1-Input\n");
        printf("2-Delete\n");
        printf("3-Print\n");
        printf("4-Average\n");
        printf("5-Number of successful students\n");
        printf("6-Exit\n");
        printf("Please give your choice\n");
        scanf("%d", &userInput);
        getchar();                                                              //to deal with the bug of skiping fgets.

        switch (userInput) {
            case 1:
                printf("\nGive name: ");
                fgets(student.name, 80, stdin);
                student.name[strlen(student.name)-1] = '\0';                         //to skip \n after names
                printf("\nGive grade: ");
                scanf("%d", &student.grade);

                insert(&list, student);
                printf("\nThe insertion was successful.\n");

                break;
            case 2:
                printf("\nGive name: ");
                fgets(student.name, 80, stdin);
                student.name[strlen(student.name)-1] = '\0';

                if (delete(&list, student.name))
                    printf("\nDeletion was successful.\n");
                else
                    printf("\nThe student was not found.\n");
                break;
            case 3:
                printList(list);
                break;
            case 4:
                printf("\nThe average is %.2lf\n", average(list));
                break;
            case 5:
                printf("\nThe number of successful students is %d\n", successful(list));
                break;
            case 6:
                printf("Goodbye");
                destroyList(list);
                exit(0);
        }
    }
}
