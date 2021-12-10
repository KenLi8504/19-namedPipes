#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(){
  char input[10000];
  char intermediate[10000];
  char output [10000];

  char *toChild = "toChild";
  char *toParent = "toParent";
  int pipeto = open(toChild,O_RDONLY);
  int pipefrom = open(toParent,O_WRONLY);
  //printf("The values of my pipes are %d and %d\n",pipeto,pipefrom);
  while (1){
    read(pipeto,input,10000);
    printf("Party!\n");
    strcpy(intermediate,input);
    printf("The child here received here was %s\n",input);
    //printf("The output here was %s\n",intermediate);
    int counter = 0;
    for (int i = 0; intermediate[i]!='\0'; i++) {
      //printf("This char is %c\n",intermediate[i]);
      //printf("The counter is %d",counter);
      if (counter == 0){
        if(intermediate[i] >= 'a' && intermediate[i] <= 'z') {
          intermediate[i] = intermediate[i] - 32;
          counter = counter + 1;
          //printf("OPTION 1");
        }
        else if (intermediate[i] >= 'A' && intermediate[i] <= 'Z'){
          counter = counter + 1;
          //printf("OPTION 2");
        }
      }
      else if (counter == 1){
        if (intermediate[i] >= 'a' && intermediate[i] <= 'z') {
          counter = counter - 1;
          //printf("OPTION 3");
        }
        else if (intermediate[i] >= 'A' && intermediate[i] <= 'Z'){
          intermediate[i] = intermediate[i] + 32;
          counter = counter - 1;
          //printf("OPTION 4");
        }
      }
    //printf("The new string is %s",intermediate);
    }
    strcpy(output,intermediate);
    // printf("The length of the input is %ld\n",strlen(input));
    //printf("The output here was %s\n",intermediate);
    write(pipefrom,output,10000);
}
return 0;
}
