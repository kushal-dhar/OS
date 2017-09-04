#include<stdlib.h>
#include<stdio.h>


char ** split_string(char str[], char delim){
     char **s = (char **)malloc(5 * sizeof(char *));
     for(int f=0; f != 5; ++f) {
         s[f] = malloc(50 * sizeof(char));
     }
    int i =0;
    int j =0;
     int k=0;
    while(str[i] != '\0'){
        if(str[i] != delim){
            s[j][k] = str[i];
        }
        else {
            s[j][k] = '\0';
            j++;
            k = -1;
        }
        i++;
        k++;
     }
     s[j][k] = '\0';
     s[j+1] = (char *)0;
     return s;
}


int strlenn(char str[]){
 int i =0;
 for(; str[i] != '\0'; i++);
 return i;
}

int getInputString(char str[]){
char c;
int i =0;
while((c= getchar()) != EOF && (c != '\n')){
str[i] =c;
++i;
}
str[i] ='\0';
return i;
}

char * tokenizeTheString(char str[], int len, char delim){
   int i, j; 
   i=j=0;
  char * final_string = (char*)malloc(sizeof(char) * (len-1));
  while(i < len){
     if(str[i] != delim){
     final_string[j] = str[i];
     ++j;
     }
     ++i;
   }
  return final_string;
}
