#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#define SIZE 10
struct student{
	char name[100], branch[50];
	int rno, year, marks[5];
	double per, avg;
};
void display(struct student s){
	printf("name: %s\nroll no: %d\nyear: %d\nbranch: %s\n", s.name, s.rno, s.year, s.branch);
	for(int index = 0; index < (sizeof( s.marks ) / sizeof( s.marks[0] )); index++){
		printf("marks in subject %d are: %d\n", (index + 1), s.marks[index]);
	}
	printf("average is: %lf\npercentage is: %lf\n", s.avg, s.per);

}
int sum(int marks[5]){
	int mark = 0; 
	for(int i =0; i < 5 ; ++i)mark += marks[i];
	return mark;
}
void getData(char name[100], char branch[50], int rno, int year, int marks[5], struct student * stud){	
	struct student s = *stud;	
	strncpy(stud->name, name, sizeof(stud->name));
	strncpy(stud->branch, branch, sizeof(stud->branch));
	stud->rno = rno;
	stud->year = year;
	memcpy(stud->marks, marks, 5 * sizeof(int));
	stud->avg = (double)(sum(stud->marks) / 5);
	stud->per = stud->avg;
}

int search(int roll, struct student std[SIZE]){
	for(int i =0 ; i< SIZE; ++i)
		if(roll == std[i].rno)return i;

	return -1;
}

int compare(const void * a, const void * b){
    return ( ((struct student *)b)->avg - ((struct student *)a)->avg ); 
}


void displayRankList(struct student std[SIZE]){
	printf("\n===========RANK LIST IS==========\n\n");
	qsort(std, SIZE, sizeof(struct student), compare); 
	for(int i = 0 ; i < SIZE; ++i){
		display(std[i]);
		printf("\n");
	}
}
int main(){
	struct student std[SIZE];
	printf("Enter the details of students\n");
	for(int i = 0 ; i< SIZE ; ++i){
		char name[100], branch[50];
		int rno, year, marks[5];
		printf("Enter the details of student %d", (i+1));
		printf("\nName: ");		scanf("%s", name);	
		printf("Roll No: ");		scanf("%d", &rno);
		printf("Year: ");		scanf("%d", &year);
		getchar();
		printf("Branch: ");		scanf("%s", branch);
		printf("Marks in 5 subjects: \n");		
		for(int  mark = 0 ; mark < 5 ; ++mark)	scanf("%d", &marks[mark]);
		
		getData(name, branch, rno, year, marks, &std[i]);
	}
	printf("Enter the roll no of the student of which you want to search the details: ");
	int roll;	scanf("%d", &roll);
	int pos = search(roll, std);
	if(pos == -1)printf("You have entered a WRONG ROLL NO\n");
	else display(std[pos]);

	displayRankList(std);
}