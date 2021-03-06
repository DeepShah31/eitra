#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>
//create user defined semun for initializing the semaphores

//writer first priority 

int a=0;
int flag=0;
void *reader(void *arg)
{
    while(flag!=1);         //wait while flag not equal to 1 means writer first execute
    printf("reader start\n");
    int semid;
    semid = (int)arg;

    //in order to perform the operations on semaphore
    // first need to define the sembuf object
    struct sembuf op1,op2;

    //operation for 0th semaphore
    op1.sem_num = 0; //signifies 0th semaphore
    op1.sem_op = -1; //reduce the semaphore count to lock
    op1.sem_flg = 0; //wait till we get lock on semaphore

    //operation for 1th semaphore
    op2.sem_num = 1; //signifies 0th semaphore
    op2.sem_op = -1; //reduce the semaphore count to lock
    op2.sem_flg = 0; //wait till we get lock on semaphore

    //locking the 0th semaphore
    if (semop(semid,&op1,1) == -1)
      {
        perror("reader:semop failure Reason:");
        exit(-1);
      }
    // else
    //   fprintf(stderr,"reader:Successfully locked 0th semaphore\n");
    //lock the 1th semaphore
    if (semop(semid,&op2,1) == -1)
      {
        perror("reader:semop failure Reason:");
        exit(-1);
      }
    // else
    //   fprintf(stderr,"reader:Successfully locked 1th semaphore\n");
      printf("a=%d\n",a);


    //release the 0th semaphore
    op1.sem_num = 0; //signifies 0th semaphore
    op1.sem_op = 1; //reduce the semaphore count to lock
    op1.sem_flg = 0; //wait till we get lock on semaphore

    if (semop(semid,&op1,1) == -1)
      {
        perror("reader:semop failure Reason:");
        exit(-1);
      }
    // else
    //   fprintf(stderr,"reader:Successfully unlocked 0th semaphore\n");

    //release the 1th semaphore
    op2.sem_num = 1; //signifies 0th semaphore
    op2.sem_op = 1; //reduce the semaphore count to lock
    op2.sem_flg = 0; //wait till we get lock on semaphore

    if (semop(semid,&op2,1) == -1)
      {
        perror("reader:semop failure Reason:");
        exit(-1);
      }
    // else
    //    fprintf(stderr,"reader:Successfully unlocked 1th semaphore\n");
      printf("reader end\n");
      flag=0;
}

void *writer(void *arg)
{
    while(flag!=0);
    printf("writer start\n");
    int semid;
    semid = (int)arg;

    //in order to perform the operations on semaphore
    // first need to define the sembuf object
    struct sembuf op1,op2;

    //operation for 0th semaphore
    op1.sem_num = 0; //signifies 0th semaphore
    op1.sem_op = -1; //reduce the semaphore count to lock
    op1.sem_flg = 0; //wait till we get lock on semaphore

    //operation for 1th semaphore
    op2.sem_num = 1; //signifies 0th semaphore
    op2.sem_op = -1; //reduce the semaphore count to lock
    op2.sem_flg = 0; //wait till we get lock on semaphore

    //lock the 0th semaphore
    if (semop(semid,&op1,1) == -1)
      {
        perror("Reason:");
        exit(-1);
      }
    // else
    //   fprintf(stderr,"writer:Successfully locked 0th semaphore\n");

    //lock the 1th semaphore
    if (semop(semid,&op2,1) == -1)
      {
        perror("Reason:");
        exit(-1);
      }
    // else
    //   fprintf(stderr,"writer:Successfully locked 1th semaphore\n");
      a++;
    //release 0th semaphore

    op1.sem_num = 0; //signifies 0th semaphore
    op1.sem_op = 1; //reduce the semaphore count to lock
    op1.sem_flg = 0; //wait till we get lock on semaphore

    if (semop(semid,&op1,1) == -1)
      {
        perror("Reason:");
        exit(-1);
      }
    // else
    //   fprintf(stderr,"writer:Successfully unlocked 0th semaphore\n");

    //release the 1th semaphore
    op2.sem_num = 1; //signifies 0th semaphore
    op2.sem_op = 1; //reduce the semaphore count to lock
    op2.sem_flg = 0; //wait till we get lock on semaphore

    if (semop(semid,&op2,1) == -1)
      {
        perror("Reason:");
        exit(-1);
      }
    // else
    //    fprintf(stderr,"writer:Successfully unlocked 1th semaphore\n");
      printf("writer end\n");
      flag=1;
}

int main()
{
    pthread_t tid1,tid2;
    int semid;

    //create user defined semun for initializing the semaphores

    typedef union semun
    {
      int val;
      struct semid_ds *buf;
      ushort * array;
    }semun_t;

    semun_t arg;
    semun_t arg1;

    //creating semaphore object with two semaphore in a set
    //viz 0th & 1th semaphore
    semid = semget(IPC_PRIVATE,2,0666|IPC_CREAT);
    if(semid<0)
      {
        perror("semget failed Reason:");
        exit(-1);
      }

    //initialize 0th semaphore in the set to value 1
    arg.val = 1;
    if ( semctl(semid,0,SETVAL,arg)<0 )
      {
        perror("semctl failure Reason:");
        exit(-1);
      }
    //initialize 1th semaphore in the set to value 1
    arg1.val = 1;
    if( semctl(semid,1,SETVAL,arg1)<0 )
      {
        perror("semctl failure Reason: ");
        exit(-1);
      }

    //create two threads to work on these semaphores
    if(pthread_create(&tid1, NULL,reader, semid))
      {
        printf("\n ERROR creating thread 1");
        exit(1);
      }
    if(pthread_create(&tid2, NULL,writer, semid) )
      {
        printf("\n ERROR creating thread 2");
        exit(1);
      }
    //waiting on these threads to complete
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    //once done clear the semaphore set
    if (semctl(semid, 1, IPC_RMID ) == -1 )
      {
        perror("semctl failure while clearing Reason:");
        exit(-1);
      }
    //exit the main threads
    pthread_exit(NULL);
    return 0;
}
