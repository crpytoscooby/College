/*

Assignment No. 8: 

Inter-process Communication using Shared Memory using System V. Application to
demonstrate: Client and Server Programs in which server process creates a shared memory segment and
writes the message to the shared memory segment. Client process reads the message from the shared
memory segment and displays it to the screen.

*/



#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<stdio.h>
#include<string.h>
#include<memory.h>
int main()
{	int retval,shmid;
	void *memory=NULL;
	char *p;
	shmid=shmget((key_t)123456789,6,IPC_CREAT|0666);
	if(shmid<0)
		printf("Failure in creation ");
	
	printf("\n We are getting the shared memory created %d \n",shmid);
	memory=shmat(shmid,NULL,0);
	if(memory==NULL)
	{	printf("\n Attachment failure");
		return 0;
	}
	p=(char *)memory;
	printf("\n MESSAGE is %s \n",p);
	retval=shmdt(p);
	if(retval<0)
	{
		printf("detachment failure");
		return 0;
	}
	retval=shmctl(shmid,IPC_RMID,NULL);
return 0;
}



/*

OUTPUT:




 We are getting the shared memory created 2490380 


 We are getting the shared memory created 2490380 

 MESSAGE is hello 



*/
