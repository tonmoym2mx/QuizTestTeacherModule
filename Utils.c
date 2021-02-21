#include <stdio.h>
#include <stdlib.h>

void inputPassword(char *password){


    char c;
   int index = 0;
   while((c = getch()) != 13){
       if(index < 0)
           index = 0;
       if(c == 8 && index >0 ){
           putch('\b');
           putch(NULL);
           putch('\b');
           index--;
       continue;
       }
       password[index++] = c;
       putch('*');
   }
   password[index] = '\0';
}
void inputValidPassword(char *password){
     while(1){
    inputPassword(password);
    if(!strlen(password)<=0){
       break;
    }else{
        printf("\nEnter valid password: ");
    }

   }
   printf("\n");
}
void createExamFile(char *password){
   char com[] = "7z a -tzip examfile.xm \*.csv -p";
   strcat(com,password);
   printf("%s\n",com);
   system(com);
   system("cls");
}
