#include <stdio.h>

#define MAX_BLOCKS 20 

int main (){

	int next [MAX_BLOCKS] ;
	
	int i , j ,n ,num_blocks ,blocks ;
	
	char fname[20] ;
	
	for (i = 0 ; i < MAX_BLOCKS ;i++ ) {
	
		next[i] =-2 ;

	}

	printf("Enter The Numnber Of Files :" ) ;
	
	scanf("%d" ,&n );
	
	for (i = 0 ; i < n; i++ ){

		printf("\n File Name :" );
		
		scanf("%s",fname);
		
		printf("Enter The Number Of Blocks :" );
		
		scanf("%d",&num_blocks);

		
		int blocks[num_blocks] ;
	
		printf("Enter The Block Number :");
		
		for (j = 0 ; j < num_blocks ;j++ ){

			scanf("%d" ,&blocks[j] );


		} 
		
		for ( j = 0 ;j < num_blocks ;j++ ){

			next[blocks[j]] = blocks[j+1] ;
			
			next[blocks[num_blocks-1]] =-1 ;


		}
		
		printf("File : %s | Chain: ",fname );
		
		int cur = blocks[0] ;
	
		while (cur != -1){
			
			printf("[blocks %d] -> ",cur );
			
			cur = next[cur] ;

		}
		
		printf("NULL \n" );
	}

	return 0 ;
}
