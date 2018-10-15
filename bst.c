#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node * left, *right;
};
struct node * newNode(int no){
	struct node * temp = (struct node *) malloc(sizeof(struct node));
	temp->data = no;
	temp->left = temp->right = NULL;
}

struct node * insert(struct node * root, int no){
	if(root == NULL){
		root = newNode(no);
		return root;
	}
	if(root->data > no){
		// insert in left subtree
		return insert(root->left, no);
	}else
	return insert(root->right, no);
}
void preOrdertraversal(struct node * root){
	if(root == NULL){
		return;
	}
	// data left right
	printf("%d ", root->data);
	preOrdertraversal(root->left);
	preOrdertraversal(root->right);

}
void postOrdertraversal(struct node * root){
	if(root == NULL){return;}
	// left right data

	postOrdertraversal(root->left);
	postOrdertraversal(root->right);
	printf("%d ", root->data);
}
void inOrderTraversal(struct node * root){
	if(root == NULL){return;}

	// left data right 

	inOrderTraversal(root->left);
	printf("%d ", root->data);	
	inOrderTraversal(root->right);
}

void swap(int *pa, int *pb){
	*pa = *pa  + *pb;
	*pb = *pa - *pb;
	*pa = *pa - *pb;
}
struct node * deleteNode(struct node * root, int no){
	if(root == NULL){
		return root;
	}
	
	struct node * p = NULL , *q = root;
	while(q!= NULL && q->data != no){
		if(q->data > no){
			p = q;
			q = q->left;

		}
		else if (q->data < no){
			p = q;
			q = q->right;
		}
	}
	if(q == NULL){
		printf("No is not present in the tree\n");
		return root;
	}
	if(q->left == NULL && q->right == NULL){
		// leave node
		if(p->data > q->data)	p->left = NULL;
		else if(p->data < q->data) p->right = NULL;
		free(q);
		return root;
	}
	// one child node
	if(q->left == NULL){
		if(p->data > q->data)p->left = q->right;
		else if(p->data < q->data)p->right = q->right;

		free(q);
		return root;
	}
	if(q->right == NULL){
		if(p->data > q->data)p->left = q->left;
		else if(p->data < q->data)p->right = q->left;
		free(q);
		return root;		
	}
	// two child node
	struct node * max = q->left;
	struct node * temp ;
	while(max->right != NULL){
		temp = max;
		max = max->right;
	}
	swap(&max->data, &q->data);
	temp->right = NULL;
	free(max);

	return root;
}
int main(){
	char cont;
	do{
		
		printf("1--> Insert\n");			
		printf("2--> Delete\n");
		printf("3--> Traversal\n");
		printf("Enter your choice\n");
		int choice;		scanf("%d", &choice);
		struct node *root = NULL;
		 int data;

		switch(choice){
			case 1 :
					scanf("%d", &data);
					root = insert(root, data);
					break;
			case 2 : 
					scanf("%d", &data);
					root = deleteNode(root, data);
					break;
			case 3 : printf("Pre Order Traversal is : \n");
					preOrdertraversal(root);
					printf("\n");
					printf("Post Order Traversal is : \n");
					postOrdertraversal(root);
					printf("\n");				
					printf("In Order Traversal is : \n");
					inOrderTraversal(root);
					printf("\n");
					break;
			default : printf("Wrong Choice\n");				
		}
		printf("Do you want to continue(y/n)\n");
		scanf(" %c", &cont);
	}while(cont == 'Y' || cont == 'y');
}