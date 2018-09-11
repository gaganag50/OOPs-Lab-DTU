#include<stdio.h>
int insert(int arr[10], int data, int len){
	if(len == 10)return -1;
	arr[len] = data;
	return ++len;
}
int delete(int arr[10], int len){
	
	arr[--len] = -1;
	return len;
}
void update(int arr[10], int data, int len){
	arr[len - 1] = data;
}
int search(int arr[10], int data, int len){
	for(int i= 0; i < len; ++i)
		if(arr[i] == data)
			return i;
	return -1;
}

void traverse(int arr[10], int len){
	for(int i = 0; i < len; ++i)	printf("%d ", arr[i]);
		printf("\n");
}
int main(){
	char cont;
	int len = 0, arr[10];
	do{
		printf("Enter your choice from the following options\n");
		printf("1--> insert\n");
		printf("2--> delete\n");
		printf("3--> update\n");
		printf("4--> search\n");
		printf("5--> traverse\n");
		int choice;
		scanf("%d", &choice);
		
		int item;
		switch(choice){
			case 1 : printf("Enter the number to be inserted ");
						scanf("%d", &item);
						len = insert(arr, item, len);
						printf("Array after inserting\n");	traverse(arr, len);
						break;
			case 2 : len = delete(arr, len);
						printf("Array after deleting\n");	traverse(arr, len);
						break;
			case 3 : printf("Enter the number to insert ");
						scanf("%d", &item);
						update(arr, item, len);
						printf("Array after updating\n");	traverse(arr, len);
						break;
			case 4 : printf("Enter the number to search ");
						scanf("%d", &item);
						int pos = search(arr, item, len);
						if(pos == -1)printf("Number is not present\n");
						else printf("Number is present at position %d\n", pos);
					break;
			
			case 5 : traverse(arr, len);
					break;
			default : printf("Wrong choice\n");

		}
		
		printf("Whether you want to continue or not?(y/n)\n");
		scanf(" %c", &cont);
	}while(cont == 'y' || cont == 'Y');
}