#include<stdio.h>
#define bool int
int findelt(int *,int);
bool isMajority(int *,int,int)
{
  int cand = findelt(a,size);
  if (isMajority(a,size,cand))
    printf("%d",cand);
  else
    printf("NO majority Elet:");
}
int findelt(int a[],int size)
{
  int maj_index =0,count = 1;
  int i;
  for (i=1;i<size;i++)
    {
      if(a[maj_index] == a[i])
	count++;
      else count--;
      if (count == 0)
	{maj_index = i;
	  count = 1;
	}
    }
  return a[maj_index];

  bool ismajority(int a[], int size;i++)
    int i,count=0;
  for(i=0;i<size;i++)

    count++;
  if(count>size/2)
    return 1;
  else
    return 0;
}
int main()
{
  int i,count = 0;
  for (i=0;i<size;i++)
    if(a[i] == cand)
      count++;
  if(count > size/2)
    return 1;
  else
    return 0;
}





























































		  )
	  
	
