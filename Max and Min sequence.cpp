#include <stdio.h>
void minimumSort(int arr[], int n) 
{
    for (int i = 0; i < n - 1; i++) 
	{
        for (int j = 0; j < n - i - 1; j++) 
		{
            if (arr[j] > arr[j + 1]) 
			{
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void maximumSort(int arr[], int n) 
{
    for (int i = 0; i < n - 1; i++) 
	{
        for (int j = 0; j < n - i - 1; j++) 
		{
            if (arr[j] < arr[j + 1]) 
			{
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int main() 
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) 
	{
        scanf("%d", &arr[i]);
    }
    minimumSort(arr, n);
    printf("Minimum Sequence:\n");
    for (int i = 0; i < n; i++) 
	{
        printf("%d ", arr[i]);
    }
    printf("\n");
    maximumSort(arr, n);
    printf("Maximum Sequence:\n");
    for (int i = 0; i < n; i++) 
	{
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

