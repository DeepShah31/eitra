#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *print_message_function (void *ptr);

int main ()
{
  pthread_t thread1, thread2;
  char *message1 = "I am Thread 1";
  char *message2 = "I am Thread 2";
  int iret1=5, iret2=10;

	pthread_attr_t tattr;
	int ret;
	ret = pthread_attr_init(&tattr);
	
   
	pthread_attr_setscope(&tattr,PTHREAD_SCOPE_PROCESS);
	/*The pthread_attr_setscope() function sets the contention scope
       attribute of the thread attributes object referred to by attr to the
       value specified in scope.*/


  /* Create independent threads each of which will execute function */

  iret1 = pthread_create (&thread1,&tattr, print_message_function,
			  (void *) message1);
  iret2 = pthread_create (&thread2, &tattr, print_message_function,
		    (void *) message2);
   //iret2 = pthread_detach(thread2);
	 pthread_attr_setdetachstate(&tattr,PTHREAD_CREATE_JOINABLE);

  /* Wait till threads are complete before main continues. Unless we  */
  /* wait we run the risk of executing an exit which will terminate   */
  /* the process and all threads before the threads have completed.   */

/* */
pthread_join (thread1, NULL);
pthread_join (thread2, NULL);
/* */
  printf ("Thread 1 returns: %d\n", iret1);
  printf ("Thread 2 returns: %d\n", iret2);
  //while(1);
  exit (0);
	return 0;
}

void *print_message_function (void *ptr){
  char *message;
  message = (char *) ptr;
  printf ("%s \n", message);
}