#include <stdio.h>
#include <stdlib.h>
#include "stringoper.h"
#include "binaryoper.h"
#include "cdoper.h"

/*char * getPath(char s[]){
int pathLen = strlenn(s);
char * path=(char*)malloc( 70 * sizeof(char));
int i , j;
for( i =7, j=0 ; i < pathLen; i++, j++) {
 path[j] = s[i];
}
path[j] = '\0';
return (char *) path;
}*/

/*
int verifyAndRunScript(char s[]){
//char *path = getPath(s);
char *path = s;
char *argv[5] = {chmod 
FILE *file = fopen(path, "r");
if(file != NULL){
	char temp[50];
        int count = 0;
        char delim = ' ';
	while(!feof(file)){
                printf("lines %s\n",temp); 
		if(count == 2){
			if(fgets(temp, sizeof(file),file)!= NULL){
            			if(temp[0] != '\n')
					checkForBinary(temp,delim);
			}
	 	}
         	if(count == 0){
			if(fgets(temp, sizeof(file),file) != NULL){
				if(temp[0] == '#' && temp[1] == '!'){
     					count = 2;
    				}
				else{
         				fclose(file);
         				return 0;  
				}
			} 
		}
	}
fclose(file);
return 1;
}
else{
	perror("File path doesn't exist");
}
fclose(file);
return 0;
}
*/

void  verifyAndRunScript(char path[],char delim){
 FILE *file ;
 int count;
 char temp[60];
 count = 0;
 int len ;
 char *tokenized;
 if((file = fopen(path,"rwx")) == NULL){
      perror("file path is not found");
 }
 while(fgets(temp,sizeof(temp),file) != NULL){
    len = strlenn(temp);
    temp[len - 1] = '\0';
    if ((count !=0) && (temp[0] != ' ') && (temp[0] != '\0') &&
      (temp[0] != '\r') && (temp[0] != '\n')){
       printf("Line read in file : %s \n",temp);
       tokenized = tokenizeTheString(temp, len, delim);     
       if(cdCalled(tokenized) == 1){
 		 checkForCD(tokenized, len);
       }else{
       checkForBinary(temp,delim);
   	}
     }
     count++;
}
}

int scriptCalled(char str[]){
int len = strlenn(str);
char delim = ' ';
int i ,k;
if(len > 8){
	if(str[len-6] == '.' && str[len-5] == 's' && str[len-4] == 'b'
	 && str[len-3] == 'u' && str[len-2] == 's' && str[len-1] == 'h' ){  
        	if(str[0] != 'c' && str[1] != 'h' &&
                 str[2] != 'm' && str[3] != 'o' && str[4] != 'd'){
                char  ch[100] = {'c','h','m','o','d',' ','a','+','x',' '};
                k = 0;
                i =10; 
                for( ; i < 10+len ; i++, k++){
                ch[i] = str[k];
		}
                ch [i] = '\0';
		checkForBinary(ch,delim); 
		 }
 	return 1;
	}
}
return 0;
}

