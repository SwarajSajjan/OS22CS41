#include <stdio.h>

int main (){

	int n ,i ,j ;

	printf("Enter Number Of Process ");
	
	scanf("%d",&n);

	int pid[n],bt[n],wt[n],tat[n];

	for ( i = 0 ; i < n ; i++ ) {
	
		printf("Enter Burst Time For p %d :",i+1);
		
		scanf("%d",&bt[i]);

		pid[i] = i+1;

	}

	wt[0] = 0 ;
	
	for ( i = 1 ;i < n ;i++ ){

		wt[i] = wt[i-1] + bt[i-1];

	}

	printf("\nPID\tBT\tWT\tTAT\n");
	
	float total_wt = 0 ;
	
	float total_tat = 0 ;
	
	for ( i = 0 ; i < n ;i++ ){

		tat[i] = wt[i] + bt[i] ;
	
		total_wt += wt[i] ;
	
		total_tat += tat[i];

		printf("P%d\t%d\t%d\t%d\n",pid[i] ,bt[i] ,wt[i] ,tat[i] ); 	

	}
	
	printf("\n Avg Waiting Time :%.2f",total_wt / n );

	printf("\n Avg Turn Arround Time :%.2f\n",total_tat / n );
	
	return 0; 

}
