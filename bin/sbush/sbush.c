#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "stringoper.h"
#include "binaryoper.h"
#include "cdoper.h"
#include "scripts.h"
#define MAX_INP 1000


int main(int argc, char *argv[], char *envp[]) {
  char input_string[MAX_INP];
  char delim = ' ';
  char p[1024];
  while(1){
  printf("%s: %s $", "sbush> ",getcwd(p,sizeof(p)));
  int input_len = getInputString(input_string);
  char *tokenized = tokenizeTheString(input_string,input_len,delim);
  if(cdCalled(tokenized) == 1){
  checkForCD(tokenized, input_len);
  }else if(scriptCalled(tokenized) == 1) {
  verifyAndRunScript(input_string,delim);
  }else{
  checkForBinary(input_string,delim);
  } 
  return 0;
}
