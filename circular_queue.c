// Program to perform basic operations in a circular queue
// 1--> Insertion
// 2--> Deletion
// 3--> Traversal

#include <stdio.h>
#define SIZE 10
struct cqueue{
	int arr[SIZE], front, rear;
};
void insert(struct cqueue *cQueue, int value){
	if(cQueue->front == (cQueue->rear + 1)%SIZE){
		printf("circular queue is full\n");
		return;
	}
	cQueue->arr[cQueue->rear] = value;
	cQueue->rear = (cQueue->rear +1 ) % SIZE;
}
int qdelete(struct cqueue *cQueue){
	if(cQueue->front == cQueue->rear ){
		printf("circular queue is empty\n");
		return -1;
	}
	int value = cQueue->arr[cQueue->front];
	cQueue->front = (cQueue->front + 1) % SIZE;
	return value;
}
void traversal(struct cqueue cQueue){
    int i;
	for(i = cQueue.front; i < (cQueue.rear ); ++i){
		printf("%d ", cQueue.arr[i]);
	}
	printf("\n");
}
int main(){
	struct cqueue cQueue;
	cQueue.front = 0;
	cQueue.rear = 0;
    char cont;
	do{
		int choice;
		printf("1--> Insertion");
		printf("\n2--> Deletion");
		printf("\n3--> Traversal");
		printf("\nEnter your choice ");
		scanf("%d", &choice);
		switch(choice){
			case 1 : printf("\nEnter element to be inserted\n");
                int value;
				scanf("%d", &value);
				insert(&cQueue, value);
				break;
			case 2 : printf("Element qdeleted is %d", qdelete(&cQueue));
				break;
			case 3 : traversal(cQueue);
				break;
			default : printf("Wrong choice");
				break;
		}
		printf("\nDo you want to continue(y/n)");
		scanf(" %c", &cont);
	}while(cont == 'y' || cont == 'Y');
	return 0;
}
