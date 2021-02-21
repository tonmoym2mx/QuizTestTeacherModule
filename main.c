#include <stdio.h>
#include <stdlib.h>

int main()
{


    char password[100] = "";
    printf("Please enter the password for encrypt question file\n");
    printf("\nEnter Password: ");
    inputValidPassword(password);
    system("cls");


   openFile();
   createCheckFile();
   addQuestion();
   fileClose();

   createExamFile(password);


    return 0;
}
