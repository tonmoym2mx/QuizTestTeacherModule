#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int opId = 0;

FILE *qFile,*oFile;
void openFile(){
    qFile = fopen("question.csv","w");
    oFile = fopen("options.csv","w");
    if(qFile == NULL){
        exit(1);
    }
     if(oFile == NULL){
        exit(1);
    }
}
char addOptions(int qId){
    char opStr[256] ,  ret[256] = "<-", strQid[5],strOpid[5],opNum = 'A',opn[2];

    while(1){

        ++opId;

        printf("\tEnter option (%c) : ",opNum);
        gets(opStr);
        if(strcmp(opStr,"<-") == 0){

            break;
        }
        itoa(opId,strOpid,10);
        itoa(qId,strQid,10);
        opn[0] = opNum;
        opn[1] = '\0';

        //printf("%s",opn);

        fputs(strcat(strOpid,","),oFile);
        fputs(strcat(strQid,","),oFile);
        fputs(strcat(opn,","),oFile);

        fputs(strcat(opStr,"\n"),oFile);
        opNum++;
       // fputs("\n",oFile);

    }
    return opNum;


}
void addAns(char maxOption){
     char ansString[100];

     printf("\tEnter Ans: ");
     gets(ansString);

     int i =0, isInvalid = 0;

     while(ansString[i]!='\0')
     {
        if(ansString[i]==',')
        {

            ansString[i]='-';
        }else{

            char c = ansString[i];

            if( (c <'A' || c > maxOption) )
                isInvalid = 1;


        }
        i++;
     }
     if (isInvalid == 1 || strlen(ansString) <= 0){
        printf("\n\tPlease type valid answer\n");
        addAns(maxOption);
     }else{
         fputs(strcat(ansString,",00\n"),qFile);
         system("cls");
     }


}

void addQuestion(){
    int c=0;
    while(1){
        char str[256],id[5],strType[]="NA";
        int type = 0;


        printf("Enter %d number question: ",++c);
        gets(str);
        itoa(c, id, 10);
        if(strcmp(str,"<-") == 0){
            break;
        }
        fputs(strcat(id,","),qFile);
        fputs(strcat(str,","),qFile);

        //do{
            // printf("Enter Type (1 for multiple 2 for single ): ");
             //scanf("%d",&type);
             //fflush(stdin);
        //}while(type != 1  && type != 2);
        itoa(type, strType, 10);
        fputs(strcat(strType,","),qFile);


        char max = addOptions(c)-1;
        addAns(max);


    }



}
void fileClose(){
    fclose(qFile);
    fclose(oFile);
}
