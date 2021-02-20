#include <stdio.h>
#include <stdlib.h>

int main()
{


    char password[100] = "";
    printf("Please enter the password for encrypt question file\n");
    printf("\nEnter Password: ");
   while(1){


    inputPassword(password);
    if(!strlen(password)<=0){
       break;
    }else{
        printf("\nEnter valid password: ");
    }

   }
   printf("\n");
   char com[] = "7z a -t7z txt.7z e\* -p";
   strcpy(com,password);

   printf("%d",com);

   openFile();
   addQuestion();
   fileClose();



    return 0;
}
