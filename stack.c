#include <stdio.h>
#include <stdbool.h>
void push(int arr[10], int data, int * len){
	(*len)++;
	if((*len) == 10){
		printf("Stack is full\n");
		return;
	}
	arr[(*len)] = data;
}
void pop(int arr[10], int * len){
	if((*len) == -1){
		printf("Stack is empty\n");
		return;
	}
	arr[(*len)] = -1;	
	(*len)--;
}

bool isFull(int arr[10], int len){
	return len == 9;
}
bool isEmpty(int arr[10], int len){
	return len == -1;
}
void traverse(int arr[10], int len){
	for(int i = 0; i <= len ; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main(){
	char cont;
	int len = -1, arr[10];
	do{	
		printf("Enter your choice from the following options\n");
		printf("1--> push\n");
		printf("2--> pop\n");
		printf("3--> traverse\n");
		printf("4--> isEmpty\n");
		printf("5--> isFull\n");
		int choice;
		scanf("%d", &choice);
		bool isempty, isfull;
		int item;
		switch(choice){	
			case 1 : printf("Enter the number to be inserted ");
						scanf("%d", &item);
						push(arr, item, &len);					
						break;
			case 2 : pop(arr, &len);
						break;
			case 3 : traverse(arr, len);
						break;
			case 4 : isempty = isEmpty(arr, len);
						if(isempty)printf("Stack is empty\n");
						else printf("Stack is not empty \n");
					break;
			
			case 5 : isfull = isFull(arr, len);
						if(isfull)printf("Stack is full\n");
						else printf("Stack is not full \n");
					break;
			default : printf("Wrong choice\n");		
		}

		printf("Whether you want to continue or not?(y/n)\n");
		scanf(" %c", &cont);
	}while(cont == 'y' || cont == 'Y');		
}