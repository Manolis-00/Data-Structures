#include <stdio.h>
#include "doubleLinkedList.h"

int main()
{
    LIST_PTR studentList;
    element student;
    char temporary[100];
    int userInput;

    initializeDoubleLinkedList(&studentList);

    while (TRUE)
    {
        printf("   This is the Menu\n");
        printf("======================\n");
        printf("1 - Add Student\n");
        printf("2 - Delete Student\n");
        printf("3 - Search Student by Registry Number\n");
        printf("4 - Search Student by Name\n");
        printf("5 - Modify Student's Data\n");
        printf("6 - Create a List of Students with the same Semester\n");
        printf("7 - Print all Students\n");
        printf("8- Print all Students of the Same Semester\n");
        printf("9 - Exit\n");
        scanf("%d", &userInput);
        getchar();

        switch (userInput)
        {
            case 1:
                printf("\nGive name: ");
                fgets(student.studentName, 100, stdin);
                student.studentName[strlen(student.studentName) - 1] = '\0';

                printf("\nGive register number: ");
                fgets(student.studentRegister, 20, stdin);
                student.studentRegister[strlen(student.studentRegister) - 1] = '\0';

                printf("\nGive semester: ");
                scanf("%d", &student.studentSemester);

                insertStartDoubleLinkedList(&studentList, student);
                break;
            case 2:
                printf("\nGive name: ");
                fgets(student.studentName, 100, stdin);
                student.studentName[strlen(student.studentName) - 1] = '\0';

                if (delete(&studentList, student.studentName))
                    printf("\nDeletion was successful\n");
                else
                    printf("\nThe student was not found\n");
                break;
            case 3:
                printf("\nGive register number: ");
                fgets(student.studentRegister, 20, stdin);
                student.studentRegister[strlen(student.studentRegister) - 1] = '\0';

                searchByRegister(&studentList, student.studentRegister);

                break;
            case 4:
                printf("\nGive name: ");
                fgets(student.studentName, 100, stdin);
                student.studentName[strlen(student.studentName) - 1] = '\0';

                searchByName(&studentList, student.studentName);

                break;
            case 5:
                printf("\nPlease give the register number for the student that you want to modify: ");
                fgets(temporary, 100, stdin);
                temporary[strlen(temporary) - 1] = '\0';

                printf("\nGive new name: ");
                fgets(student.studentName, 100, stdin);
                student.studentName[strlen(student.studentName) - 1] = '\0';

                printf("\nGive new register number: ");
                fgets(student.studentRegister, 20, stdin);
                student.studentRegister[strlen(student.studentRegister) - 1] = '\0';

                printf("\nGive new semester: ");
                scanf("%d", &student.studentSemester);

                modifyData(&studentList, temporary, student);
                break;
            case 7:
                printDoubleLinkedList(&studentList);
                break;
            case 8:
                printf("\nPlease give the semester that you desire: ");
                scanf("%d", student.studentSemester);
                printDoubleLinkedListBySemester(&studentList, student.studentSemester);
            case 9:
                printf("\nGoodbye\n");
                destroyDoubleLinkedList(studentList);
                exit(0);
        }
    }

}
