#define _POSIX_SOURCE
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "stringoper.h"

void checkForBinary(char str[], char delim){
pid_t child_id ;
char* const* s = split_string(str,delim);
//printf("str is %s",str);
//printf("%s\n", s[0]);
//printf("%s\n", s[1]);
int i= -1;
int status=0;
if((i = fork()) == 0){
	if(execvp(s[0], s)< 0){ 
		 perror("execvp error");
	}
}

while((child_id = wait(&status)) > 0);
fflush(NULL);
}
