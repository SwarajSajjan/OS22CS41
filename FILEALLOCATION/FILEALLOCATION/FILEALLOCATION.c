#include <stdio.h>

#define MAX_BLOCKS 50 

int main (){

	int disk [MAX_BLOCKS] = {0};

	int n , i , j ,start , length ;
	
	char fname[MAX_BLOCKS]; 

	printf("Enter The NUmber Of Files :" );
	
	scanf("%d",&n );
	
	printf("\n%-10s %-8s %-8s %s \n" ,"File" ,"Start" ,"Length" ,"Blocks" );
	
	printf("---------------------------------------\n");
	
	for (i = 0 ; i < n ;i++ ){
	
		printf("Enter The File Name ,Start Block ,Length ");
		
		scanf("%s %d %d",fname ,&start ,&length );
		
		int ok = 1 ;
		
		for (j = start ;j < start + length ;j++ ){

			if (j >= MAX_BLOCKS || disk[j]){
				
				ok = 0 ;
				
				break;

			}

		}


		if (!ok){
			
			printf("ERROR :Blocks Not Available For %s\n",fname);
		
			continue ;


		}
		
		printf("%-10s %-8d %-8d ",fname ,start ,length);
		
		for (j = start ;j < start + length ;j++){
			
			disk[j] = 1 ;

			printf("%d",j);


		}
		printf("\n");
		

	}
	return 0 ;


}
