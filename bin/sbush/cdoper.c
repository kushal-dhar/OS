#include <stdlib.h>
#include <stdio.h>
#include <unistd.h> 
#include <errno.h>

int cdCalled(char str[]){
if(str[0] == 'c' && str[1] == 'd'){
return 1;
}
return 0;
}


void checkForCD(char str[], int path_len){
char path [500];
int ret = -1;
char curr_dir[1024] ;
if(getcwd(curr_dir,sizeof(curr_dir)) != NULL){
if(str[0] == 'c' && str[1] == 'd'){
  int i =0;
  if (str[2] != '/'){
 	 for( ; curr_dir[i] != '\0';++ i){
        	path[i]= curr_dir[i];
    	  }
	  path[i] = '/';
	i++;
  }
for(int j =2; str[j] != '\0'; j++){
path[i] = str[j];
i++;
}
path[i]= '\0';
ret = chdir(path);
if(ret != 0){
perror( "Directory is not changed, probably wrong address\n");
}
}
}
}
