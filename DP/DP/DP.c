#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 5

sem_t fork_sem[N];

void *philosopher(void *arg){
	
	int id = *(int *)arg ;
	
	int left  = id;
	
	int right = (id + 1) % N ;

	printf("Philosopher %d is THINKING \n",id );
	
	sleep(1) ;
	
	if (left < right){

		sem_wait(&fork_sem[left]);

		sem_wait(&fork_sem[right]);
	}else{
		sem_wait(&fork_sem[right]);

		sem_wait(&fork_sem[left]);
	}

	printf("Philosopher %d is EATING \n",id );

	sleep(1);

	sem_post(&fork_sem[left]);

	sem_post(&fork_sem[right]);
	
	printf("Philosopher %d Finished Eating \n ",id );
	
	return NULL ;
 	

}

int main (){
	
	pthread_t tid[N] ;
	
	int id[N];
	
	int i;

	for (i = 0 ;i < N ;i++ ){

		sem_init(&fork_sem[i] ,0,1 );	

	}
	
	for (i = 0 ; i < N ;i++){
	
		id [i] = 1;
		
		pthread_create(&tid[i] ,NULL,philosopher ,&id[i]);
	}
	
	for (i = 0 ; i < N ;i++ ){

		pthread_join(tid[i],NULL);

	}

	for ( i = 0 ; i < N ;i++){
		
		sem_destroy(&fork_sem[i]);

	}
	
	return 0;
}

