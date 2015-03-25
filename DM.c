
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void ReplaceStudentName();
void ReplaceWord();
void ReplacePhrase();
void HideMsg();
char *replace_str();


int main() {
   
  char *para;

   printf("Enter Your Reccomendation Letter Below: ");
   scanf("%[^\t]s", para);
   if (para!=NULL)
   {
   		printf("You can choose one of the following options by input choice letter: \n"
   				"A. Replace student name\n"
   				"B. Replace specific word\n"
   				"C. Replace a phrase\n"
   				"D. Hide message\n");
        char *letter=malloc(1);
   		scanf("%s",letter);
   		
   		if (strcmp(letter,"A")==0){

   			ReplaceStudentName(para);
        printf("Your paragraph now is : %s\n", para);
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
   		//printf("Your paragraph now is : %s\n", para);

   }
   /*else if (para[0]=='\0') {
   	printf("Your input is empty! Please enter your reccomendation below:\n");
   	scanf("%[^\t]s", para);

   }*/

   
   return 0;

}

 void ReplaceStudentName(char *para){
  para=malloc(1000);
	char *CurFirstName=malloc(15);
	char *NewFirstName=malloc(15);

	printf("Please Type in the Current Student First Name and Hit Enter: \n");
	scanf("%s",CurFirstName);
	//printf("Please Type in the Current Student Last Name and Hit Enter: \n");
	//scanf("%s",CurLastName);
	printf("Please Type in the New Student First Name: \n");
  scanf("%s",NewFirstName);
 // printf("Please Type in the New Student Last Name: \n");
  //scanf("%s",NewLastName);

  replace_str(para, CurFirstName, NewFirstName);
  //replace_str(para, CurLastName, NewLastName);
  //printf("Your paragraph now is : %s\n", para);
  return para;
}


void ReplaceWord(){

}

void ReplacePhrase(){

}

void HideMsg(){

}

char *replace_str(char *str, char *orig, char *rep)
{
  static char buffer[4096];
  char *p;

  if(!(p = strstr(str, orig)))  // Is 'orig' even in 'str'?
    return str;

  strncpy(buffer, str, p-str); // Copy characters from 'str' start to 'orig' st$
  buffer[p-str] = '\0';

  sprintf(buffer+(p-str), "%s%s", rep, p+strlen(orig));

  return buffer;
}


