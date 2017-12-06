#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#define KEY 888


int main(int argc, char **argv){

  if (argc < 2){
    printf("No specified arguments\n");
    printf("Try again using at least 1 argument in addition to the executable file\n");
    exit(1);
  }
  else if (!strcmp(argv[1], "-c")){
    int sem = semget(KEY, 1, IPC_CREAT | IPC_EXCL);
    if (sem == -1){
      printf("Failure to create semaphore\n");
      printf("Semaphore already exists\n");
    }
    else{
      semctl(sem, 0, SETVAL, argv[2]);
      printf("Set semaphore %d's value to %d\n", sem, semctl(sem, 0, GETVAL));
    }
  }
  //else if (!strcmp(arg

  return 0;
}
