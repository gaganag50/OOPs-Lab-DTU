#include<stdio.h>
void display(int *arr, int n){
	for(int i = 0; i < n ;i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 

int partition(int *arr, int b, int e){
	if(e-b == 1)return b;
	int pivot = e-1, i=b, j = b-1;
	for(int i= b; i < e-1; ++i){
		if(arr[i] < arr[pivot]){
			++j;
			swap(&arr[j], &arr[i]);
		}

	}
	++j;
	swap(&arr[j], &arr[pivot]);
	return j;
}
void quicksort(int *arr, int b, int e){
	if(b>=e)return;

	int div = partition(arr, b, e);
	
	quicksort(arr, b, div);
	quicksort(arr, div+1, e);
}
int main(){
	int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
	int n = sizeof(arr)/sizeof(int);
	printf("Array Before Sorting:\n");
	display(arr, n);
	quicksort(arr, 0, n);
	printf("Array After Sorting:\n");
	display(arr, n);
	return 0;
}