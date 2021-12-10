#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>

int main(){
  int err1 = mkfifo("user_to_worker", 0644);
if (err1<0) {
    printf("Couldn't make the fifo, error = %d\n", errno);
    return -1;
}
  //printf("The value of this pipe is %d\n",err1);
}
