#include <limits.h> 
#include <stdio.h>
void print2Smallest(int arr[], int arr_size)
{
	int i, first, second;
	if (arr_size < 2) {
		printf(" Invalid Input ");
		return;
	}
	first = second = INT_MAX;
	for (i = 0; i < arr_size; i++) {
		if (arr[i] < first) {
			second = first;
			first = arr[i];
		}
		else if (arr[i] < second && arr[i] != first)
			second = arr[i];
	}
	if (second == INT_MAX)
		printf("There is no second smallest element= \n");
	else
		printf("First smallest element = %d\n",first);
		printf("Second smallest element = %d\n",second);
}
int main()
{
	int arr[] = { 3,5,-4,0,1,2,4 };
	int n = sizeof(arr) / sizeof(arr[0]);
	print2Smallest(arr, n);
	return 0;
}

