#include<stdio.h>
#include<malloc.h>
#define MAX 20
typedef struct mygraph{
  int v_count;
  int **edges;
}graph;

typedef struct queue{
  int data[MAX];
  int F,R;
  }Q;

graph *newgraph(){
  return ((graph *)malloc(sizeof(graph)));
  }

graph *newgraph();
void setvertices(graph *g,int count);
void addEdge(graph *g,int e1,int e2);
void addWEdge(graph *g,int e1,int e2,int weight);
void display_adjmat(graph *g);
void enqueue(Q *q,int v);
int dequeue(Q *q);
int empty(Q *q);
void BFS(graph *g,int v);
void DFS(graph *g,int i,int visited[]);

int main()
{
  Q *q;
  q=(Q *)malloc(sizeof(Q));
  graph *g;
  g=(graph *)malloc(sizeof(graph));
  int i,visited[MAX];
  setvertices(g,6);
  addEdge(g,1,2);
  addEdge(g,1,3);
  addEdge(g,2,4);
  addEdge(g,3,4);
  addEdge(g,4,5);
  addEdge(g,5,6);
  display_adjmat(g);
  BFS(g,4);
  printf("DFS Ordering:");
  for(i=1;i<=g->v_count;i++)
    {
      visited[i]=0;
    }
    DFS(g,4,visited);
    printf("\n");
  return 0;
  
}

void setvertices(graph *g,int count)
{
  g->v_count=count;
  int i;
  g->edges=(int**)malloc(sizeof(int*)*count);
  for(i=1;i<=count;i++)
    {
      g->edges[i]=(int*)malloc(sizeof(int)*count);
    }
}
      
void addEdge(graph *g,int e1,int e2)
{
  g->edges[e1][e2]=1;
  g->edges[e2][e1]=1;
}

void addWEdge(graph *g,int e1,int e2,int weight)
{
  g->edges[e1][e2]=weight;
  g->edges[e2][e1]=weight;
}

void display_adjmat(graph *g)
{
  int i,j;
  for(i=1;i<=g->v_count;i++)
      printf("v[%d]",i);
  printf("\n");
  for(i=1;i<=g->v_count;i++)
    {
      printf("v[%d] ",i);
      for(j=1;j<=g->v_count;j++)
	{
	  printf(" %d ",g->edges[i][j]);
	}
      printf("\n");
    }
}

void BFS(graph *g,int v)
{
  int w,i,j,visited[g->v_count];
  Q *q;
  q=(Q *)malloc(sizeof(Q));
  q->F=q->R=-1;
  for(i=1;i<=g->v_count;i++)
    {
      visited[i]=0;
    }
  enqueue(q,v);
  printf("\nBFS Ordering: ");
  while(empty(q)==0)
    {
      v=dequeue(q);
      if(visited[v]==0)
	{
	  for(j=1;j<=g->v_count;j++)
	    {
	      if(g->edges[v][j]==1 )
		{
		  enqueue(q,j);
	     
		}
      	    }
	  printf(" %d",v);
	 }
      visited[v]=1;
    }
  printf("\n");
}

void DFS(graph *g,int i,int visited[])
{
  int j;
  printf(" %d",i);
  visited[i]=1;
  for(j=1;j<=g->v_count;j++)
    {
      if(visited[j]==0 && g->edges[i][j]==1)
	{
	  DFS(g,j,visited);
	}
    }
}
int empty(Q *q)
{
  if(q->R==-1)
    {
      return(1);
    }else{
    return(0);
  }
}

void enqueue(Q *q,int v)
{
  if(q->R==-1)
    {
      q->R=q->F=0;
      q->data[q->R]=q->data[q->F]=v;
    }
  else{
    q->R=q->R + 1;
    q->data[q->R]=v;
  }
}

int dequeue(Q *q)
{
  int x;
  x=q->data[q->F];
  if(q->F==q->R)
    {
      q->F=-1;
      q->R=-1;
    }else{
    q->F=q->F + 1;
  }
  return (x);
}
