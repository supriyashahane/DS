#include<stdio.h>
#include<stdlib.h>

struct stack
{
  struct stack *ptr;
  int data;
} *top,*temp;

int count=0;
void push(int value)
{
  if(top==NULL)
    {
      top=(struct stack*) malloc(sizeof(struct stack));
      top->data=value;
      temp->ptr=NULL;
    }
  else
    {
      temp=(struct stack*) malloc(sizeof(struct stack));
      temp->data=value;
      temp->ptr=top;
      top=temp;
    }
  count++;
}
void pop()
{
  temp=top;
  if(top==NULL){
    printf("This is wrong attempt\n");
    return;}
  printf("we are getting %d from the of stack\n",temp->data);
  temp=top->ptr;
  free(top)
  
