#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int ins[320];
double hit[29][3];
typedef struct node
{
  int data;
  struct node *next;
}node;
typedef struct
{
  node * front,*rear;
}queue;
void init(queue* LQ)
{
  LQ->front=LQ->rear=NULL;
}
void enQueue(queue *LQ,int x)
{
  node *s;
  s=(node *)malloc(sizeof(node));
  s->data=x;
  s->next=NULL;
  if(!LQ->front)
  {
    LQ->front=LQ->rear=s;
  }
  else
  {
    LQ->rear->next=s;
    LQ->rear=s;
  }
}
void deQueue(queue *LQ)
{
  //本题中不会出现空队列出队的情况，故无需判断此异常
  node *p;
  p=LQ->front;
  LQ->front=p->next;
  free(p);
  if(!LQ->front)
    LQ->rear=NULL;
}
int find(queue *LQ,int x)
{
  node *p=LQ->front;
  while(p)
  {
    if(x==p->data)
      return 1;
    p=p->next;
  }
  return 0;
}
/*随机生成指令序列
*/
void randIns()
{
  int i=0,m;
  srand((unsigned)time(NULL));
  while(i<320)
  {
    m=rand()%320;
    ins[i++]=m;
    ins[i++]=m+1;
    m=rand()%m+2;
    ins[i++]=m;
    ins[i++]=m+1;
    m=rand()%(318-m)+m+2;
    ins[i++]=m;
  }
}
/////////////////////////////////////////////
//FIFO算法
/////////////////////////////////////////////
void fifo(int n)
{
  queue que,*q;//内存页队列
  q=&que;
  init(q);
  int i,size=0;
  int sum=0;
  for(i=0;i<320;i++)
  {
    int page=ins[i]/10;
    if(find(q,page))
      sum++;
    else if(size<n)
    {
      enQueue(q,page);
      size++;
    }
    else
    {
      deQueue(q);
      enQueue(q,page);
    }
  }
  hit[n-4][0]=sum/320.0;
}
//////////////////////////////////////////////
//LRU算法
//////////////////////////////////////////////
unsigned r[32];
int p[32];
int find_page(int n,int page)
{
  int i;
  for(i=0;i<n;i++)
  {
    if(page==p[i])
    {
      r[i]+=1;
      return i+1;
    }
  }
  return 0;
}
void insert_page(int n,int page)
{
  int i;
  int maxIndex=0;
  unsigned max=r[0];
  for(i=1;i<n;i++)
  {
    if(r[i]<max)
    {
      max=r[i];
      maxIndex=i;
    }
  }
  p[maxIndex]=page;
  r[maxIndex]=1;
}
void updateLRU(int n)
{
  int i;
  for(i=0;i<n;i++)
    r[i]<<=1;
}
void lru(int n)
{
  memset(r,0,sizeof(r));
  memset(p,0,sizeof(p));
  int i,sum=0,size=0;
  for(i=0;i<320;i++)
  {
    int page=ins[i]/10+1;
    if(find_page(n,page))
      sum++;
    else if(size<n)
      p[size++]=page;
    else
      insert_page(n,page);

    updateLRU(n);
  }
  hit[n-4][1]=sum/320.0;
}
////////////////////////////////////////////
//LFU算法
////////////////////////////////////////////
void lfu(int n)
{
  memset(r,0,sizeof(r));
  memset(p,0,sizeof(p));
  int i,sum=0,size=0;
  for(i=0;i<320;i++)
  {
    int page=ins[i]/10+1;
    if(find_page(n,page))
      sum++;
    else if(size<n)
      p[size++]=page;
    else
      insert_page(n,page);
    
  }
  hit[n-4][2]=sum/320.0;
}
int main()
{
  int i;
  randIns();
  for(i=4;i<=32;i++)
  {
    fifo(i);
    lru(i);
    lfu(i);
  }
  printf("|页数|FIFO| LRU| LFU|\n");
  for(i=4;i<=32;i++)
  {
    printf("| %2d |%.2lf|%.2lf|%.2lf|\n",i,hit[i-4][0],hit[i-4][1],hit[i-4][2]);
  }
return 0;
}
