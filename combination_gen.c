/* HOW TO RUN :
 * 	$cc <program_name>;
 *	$./a.out ;
 *
 * WHAT PROG DOES :
 * 	>Prints all the combination values out of 'n' values, taken 'r' at a time.
 *
 * NOTES :
 * 	>Didn't do error checking on the values of 'n' & 'r', assuming user enters them appropriately.
 *
 */


#include<stdio.h>
#include<stdlib.h>

int n,r ;
int *arr;

/**************************************************************/
void print_array( int *arr ){
	int i;
	printf("[ " );
	for( i=0 ; i<r ; i++ ){
		printf("%d " , arr[i] );

	}
	printf("]\n" );

}
/**************************************************************/
void  combination_gen( int current_arr_pos ){
	if( current_arr_pos > (r-1) ) return ;

	if( current_arr_pos == (r-1 ) ){
		/*this is last position in array, so print till 'n' */
		int i;
		for( i=arr[current_arr_pos] ; i<=n ; i++ ){
			print_array(arr);
			arr[current_arr_pos]++;
		}
		printf("**\n");

	}
	else{
		while( arr[current_arr_pos] <= ( n-r+current_arr_pos+1 ) ){
			arr[current_arr_pos+1]=arr[current_arr_pos]+1;
			combination_gen( current_arr_pos+1);
			arr[current_arr_pos]++;
		}
	}

}
/**************************************************************/
int main(){
	n=6;
	r=3;

	arr=(int *)malloc(r*sizeof(int) );
	arr[0]=1;

	combination_gen(0);

return 0;

}

