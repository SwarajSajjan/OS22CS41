#include <stdio.h>

#define MAX_P 10
#define MAX_R 10 

int main (){

	int n ,m ,i ,j ,k;
	
	printf("Enter Number Of Process : ");
	
	scanf("%d",&n);
	
	printf("Enter Number Of Porcess : " );
	
	scanf("%d",&m);

	int alloc[MAX_P] [MAX_P];
	
	int max[MAX_P][MAX_P] ;
	
	int avail [MAX_R] ;
	
	int need [MAX_P] [MAX_P] ;

	printf("Enter Allocation Matrix : ");

	for ( i = 0 ;i < n ;i++ ){
		for ( j = 0 ;j < m ;j++ ){

			scanf("%d",&alloc[i][j]);

		}

	}
	
	printf("Enter The Max Matrix :\n" );
	
	for ( i = 0; i < n ;i++ ){
		for (j = 0 ; j < m ;j++ ){

			scanf("%d",&max[i][j]);
		
			need[i][j] = max[i][j] - alloc[i][j] ;

		}


	}	
	
	printf("Enter The Available Resource : \n");
	
	for (j = 0 ; j < m ;j++ ){

		scanf("%d",&avail[j]);

	}

	int finish [MAX_P] = {0} ;
	
	int safe_seq[MAX_P] = {0} ;
	
	int count = 0 ;
	
	int work [MAX_P] ;
	
	for (j = 0 ;j < m ;j++ ){

		work[j] = avail[j] ;

	}

	while (count < n){
		
		int found  = 0 ;
		
		for (i = 0 ; i < n ; i++ ){
			
			if ( !finish[i]){
				
				int ok = 1 ;
				
				for ( j = 0 ; j < m ;j++) {
					
					if (need[i][j] > work[j]){

						ok = 0;

						break;


					}

				}
				
				if (ok){
					for ( j = 0 ; j < m ;j++) {

						work[j] += alloc[i][j];

					}
					safe_seq[count++] = i ;
					
					finish[i] = 1 ;

					found = 1;

				}	

			
			}
		}

		if (!found){
	
			break;			

		}

	}
	
	if (count == n){
		
		printf("\n System Is In Safe State \n Safe Sequence : " );
		
		for (i = 0 ; i < n ;i++){
		
			printf("P%d%s" ,safe_seq[i] ,i < n-1 ? "->" :"\n" );


		}


	}else{

		printf("Dead Locked Occured !!! \n" );

	}

	return 0 ;

} 
