#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct elt{
struct elt*next;
int data;
};

void display(struct elt *p)
{
while(p!=NULL)
{printf("%d,",p->data);
p=p->next;
}}
void addfirst(struct elt** p,int q )
{
struct elt*new=(struct elt*) malloc(sizeof(struct elt));
new->data=q;
new->next=*p;
*p=new;
}
void addlast(struct elt**p,int q)
{
struct elt* temp =(struct elt*) malloc(sizeof(struct elt));
if(*p==NULL)
 p-=temp;
while(p->next!=NULL)
{p=p->next;}
temp->data=q;
temp->next=NULL;
}
void main()
{
struct elt*head=(struct elt*) malloc(sizeof(struct elt));
struct elt*head1=(struct elt*) malloc(sizeof(struct elt));

head->data=10;
head->next=head1;

head1->data=100;
head1->next=NULL;

printf("numbers in the list are=[");
display(head);
printf("\b]\n");
printf("new list is=[");
addfirst(&head,1);
display(head);
printf("\b]\n");
}
