#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct elet
{
	struct elet* next;
	int data;
};

void display(struct elet* p)
{
	if(p==NULL)
	{return;}
	else{
	printf("%d,",p->data);}
	if(p->next==NULL)
	{return;}
	else{
	display(p->next);} 
}
int addhead(struct elet** p,int n)
{	struct elet* temp=NULL;
	temp=(struct elet*) malloc(sizeof(struct elet));	
	temp->next=*p;
	temp->data=n;
	*p=temp;
}

/*int insertend(struct elet**p,) 
{	
	if(p==NULL)
	{return;}
	else(
	if(p->next==NULL)*/
	

void BubbleSort(struct elet *p){
int n=len(p),i;
for( i=0;i<n;i++){
bubble_single_path(p);}
}
bubble_single_path(struct elet *p){
while(p){
if(p->next){
if (p->data > p->next->data)
swap(p,p->next);
}}
p<p->next;
}

void main()
{
	struct elet* head=(struct elet*) malloc(sizeof(struct elet));
	struct elet* head1=(struct elet*) malloc(sizeof(struct elet));
	struct elet* head2=(struct elet*) malloc(sizeof(struct elet));

	head->data=10;
	head->next=head1;

	head1->data=100;
	head1->next=head2;

	head2->data=1000;
	head2->next=NULL;

printf("Number in the list are=(");
display(head);
printf("\b)\n");
printf("Add element at the head of list=(");
addhead(&head,1);
display(head);
printf("\b)\n");
printf("Sorted list=(");
BubbleSort(head);
display(head);
printf("\b)\n");
}
