#include <stdio.h>

int main (){

	
	int n, i ,j , temp ;
	
	printf("Enter The Number Of Process :");
	
	scanf("%d" ,&n);

	int pid [n] ,bt[n] ,wt[n] ,tat[n] ;
	
	for (i = 0 ; i < n ;i++ ){

		pid[i] = i+1;
	
		printf("Enter Burst Time For P %d :", i+1 );
		
	   	scanf("%d" ,&bt[i] );	


	}

	for ( i = 0 ; i < n ; i++ ){
		
		for ( j = i + 1 ; j < n ; j++ ){
		
			if (bt[i] > bt [j]){

				//bt			

				temp = bt[i];

				bt[i] = bt[j];

				bt[j] = temp;

				// pid				

				temp = pid[i] ;

				pid[i] = pid [j] ;

				pid[j] = temp ;
			
			}

		}

	}

	wt[0] = 0 ;
	
	for (i = 1 ;i < n ;i++ ){

		wt[i] = wt[i-1] + bt[i-1];		

	}

	float total_wt = 0;
	
	float total_tat = 0;
	
	for( i = 0 ; i < n ;i++ ){
	
		tat[i] = wt[i] + bt[i] ;
		
		total_wt += wt[i] ;
		
		total_tat += tat[i];

		printf("P%d\t%d\t%d\t%d\n",pid[i] ,bt[i] , wt[i] , tat[i] );
	
	}
	
	printf("\n AVG Waiting Time :%.2f",total_wt / n) ;
	
	printf("\n AVG Turn Arround Time :%.2f",total_tat / n);

	return 0; 

}
