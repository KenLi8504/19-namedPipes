#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>


int main (){
  char *toChild = "toChild";
  char *toParent = "toParent";
  char input [10000];
  char output [10000];

  mkfifo(toChild,0644);
  mkfifo(toParent,0644);
  int pipeto = open(toChild,O_WRONLY);
  int pipefrom = open(toParent,O_RDONLY);
  while(1){
    printf("Enter a string: ");
    fgets(input,10000,stdin);
    char input_length_adjusted [strlen(input)];
    strcpy(input_length_adjusted,input);
    // //printf("The string was %s",input);
    write(pipeto,input_length_adjusted,10000);
    read(pipefrom,output,10000);
    printf("The output from the child was %s\n",output);
  }
  return 0;
}
