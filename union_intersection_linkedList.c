#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node * next;
	
};
struct node * newNode(int data){
	struct node * temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;
	return temp;
}
struct node * getTail(struct node * start){	
	while(start->next != NULL)start = start->next;
	return start;
}
void insert(struct node ** start, int value){
	if(*start == NULL){
		*start = newNode(value);
		return;
	}
	struct node * temp = getTail(*start);
	temp->next = newNode(value);
}
void display(struct node * start){	
	while(start != NULL){
		printf("%d " , start->data);
		start = start->next ;
	}
	printf("\n");
}
struct node * merge(struct node ** first_start, struct node ** second_start){
	if(*first_start == NULL)return *second_start;
	if(*second_start == NULL)return *first_start;
	struct node * sort ;
	if((*first_start)->data < (*second_start)->data){
		sort = *first_start;
		*first_start = (*first_start)->next;
	}else if((*first_start)->data > (*second_start)->data){
		sort = *second_start;
		*second_start = (*second_start)->next;
	}else {
		sort = *first_start;
		*first_start = (*first_start)->next;
		*second_start = (*second_start)->next;
	}
	struct node * ans = sort;
	while(*first_start != NULL && *second_start != NULL){
		if((*first_start)->data < (*second_start)->data){
			sort->next = *first_start;
			*first_start = (*first_start)->next;
			sort = sort->next;
		}else if((*first_start)->data > (*second_start)->data){
			sort->next = *second_start;
			*second_start = (*second_start)->next;
			sort = sort->next;
		}else{
			sort->next = *second_start;
			*second_start = (*second_start)->next;
			*first_start = (*first_start)->next;
			sort = sort->next;			
		}
	}
	if(*first_start != NULL){
		sort->next = *first_start;
		*first_start = (*first_start)->next;
		sort = sort->next;
	}
	if(*second_start != NULL){
		sort->next = *second_start;
		*second_start = (*second_start)->next;
		sort = sort->next;
	}
	return ans;
}

struct node * intersection(struct node ** first_node, struct node ** second_node){
	if(*first_node == NULL)return *second_node;
	if(*second_node == NULL)return *first_node;
	struct node * inter, *ans ;

	if((*first_node)->data < (*second_node)->data){
		while(*first_node != NULL  && (*first_node) -> data < (*second_node) -> data){		
			*first_node = (*first_node) -> next;
		}
		
		ans = *first_node;
		if((*first_node)->data == (*second_node)->data){			
			*first_node = (*first_node)->next;
			*second_node = (*second_node)->next;
		}

	}else if((*first_node)->data > (*second_node)->data){
		while(*second_node != NULL && (*first_node) -> data >  (*second_node) -> data)
			*second_node = (*second_node) -> next;

		ans = *second_node;
		if((*first_node)->data == (*second_node)->data){
			*first_node = (*first_node)->next;
			*second_node = (*second_node)->next;
		}
	}else{

		ans = *first_node;
		*first_node = (*first_node) -> next;
		*second_node = (*second_node)->next;
	}
	inter = ans;
	while(*first_node != NULL && *second_node != NULL){
		if((*first_node) -> data < (*second_node) ->data){
			*first_node = (*first_node) -> next;
		}else if ((*first_node) -> data > (*second_node) -> data){
			*second_node = (*second_node) -> next;
		}else{
			inter->next = *first_node;
			*first_node = (*first_node) -> next;
			*second_node = (*second_node) -> next;
			inter = inter->next;
		}
	}
	inter->next = NULL;
	return ans;
}
struct node * copy(struct node * first_start){
	struct node * temp = NULL;
	while(first_start != NULL){
		insert(&temp, first_start->data);
		first_start = first_start -> next;
	}
	return temp;
}
int main(){
	struct node * first_start = NULL, * second_start = NULL;
	int value;
	scanf("%d", &value);

	while(value != -1){		
		insert(&first_start, value);
		scanf("%d", &value);
	}
	scanf("%d", &value);

	while(value != -1){
		insert(&second_start, value);
		scanf("%d", &value);
	}
	struct node * first_node = copy(first_start), *second_node = copy(second_start);
	
	struct node * sort = merge(&first_start, &second_start);
	printf("Union of Linked Lists is : ");
	display(sort);
	struct node * inter = intersection(&first_node, &second_node);
	printf("Intersection of Linked Lists is : ");
	display(inter);
	return 0;
}

