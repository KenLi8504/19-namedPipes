#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main (){
  char input [10000];
  char output [10000];
  char *toChild = "toChild";
  char *toParent = "toParent";

  int good1 = mkfifo("toChild",0644);
  int good2 = mkfifo("toParent",0644);
  //printf("The value of my pipes are %d and %d\n",good1,good2);
  int pipeto = open(toChild,O_WRONLY);
  int pipefrom = open(toParent,O_RDONLY);
  //printf("The values of my pipes are %d and %d\n",pipeto,pipefrom);
  while(1){
    printf("Enter a string: ");
    fgets(input,10000,stdin);
    char input_length_adjusted [strlen(input)];
    strcpy(input_length_adjusted,input);
    // //printf("The string was %s",input);
    write(pipeto,input_length_adjusted,10000);
    //printf("Got up here\n");
    read(pipefrom,output,10000);
    //printf("Got up here2\n");
    printf("The output from the child was %s\n",output);
  }
  return 0;
}
