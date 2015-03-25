
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void ReplaceStudentName(void);
void ReplaceWord();
void ReplacePhrase();
void HideMsg();


int main() {
   char para[1000];
  

   printf("Enter Your Reccomendation Letter Below: ");
   scanf("%[^\t]s", para);
   if (para[0]!='\0')
   {
   		printf("You can choose one of the following options by input choice letter: \n"
   				"A. Replace student name\n"
   				"B. Replace specific word\n"
   				"C. Replace a phrase\n"
   				"D. Hide message\n");
         char *letter=malloc(1);
   		scanf("%s",letter);
   		
   		if (strcmp(letter,"A")==0){
   			ReplaceStudentName();
   		}
         else if (strcmp(letter,"B")==0){
            ReplaceWord();
         }
         else if (strcmp(letter,"C")==0){
            ReplacePhrase();
         }
         else if (strcmp(letter, "D")==0){
            HideMsg();
         }
         else{
            printf("Input is invalid.");
         }
   		printf("Your paragraph now is : %s", para);

   }
   /*else if (para[0]=='\0') {
   	printf("Your input is empty! Please enter your reccomendation below:\n");
   	scanf("%[^\t]s", para);

   }*/

   
   return 0;

}

void ReplaceStudentName(void){
   

}

void ReplaceWord(){

}

void ReplacePhrase(){

}

void HideMsg(){}


