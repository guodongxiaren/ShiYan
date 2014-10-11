#ifndef MYSQQUEUE_H
#define MYSQQUEUE_H
#endif
#include "SqQueue.h"
#include <iomanip>
template <class T>
class MySqQueue:public SqQueue<T>
{
	public:
	void display(ostream& out)const;
	void randomCreate();
};
template <class T>
void MySqQueue<T>::display(ostream& out)const
{
	for(int i=1;i<=10;i++)
		cout<<"["<<setw(2)<<i<<"]"<<" ";
	int len  = getLength();
	cout<<endl;
	for(int i=0;i%queueSize!=rear;i = (i+1)%queueSize)
		if(i<front)
			cout<<"     ";
		else
		cout<<setw(4)<<base[i]<<" ";
	cout<<endl;
	for(int i=0;i<10;i++)
		if(i!=rear&&i!=front)
		cout<<"     ";
		else
			cout<<setw(4)<<" ¡ü";
	cout<<endl;
		for(int i=0;i<10;i++)
		if(i==rear)
		cout<<"rear";
		else if(i==front)
			cout<<"front";
		else
			cout<<"     ";
	cout<<endl;
}
template <class T>
ostream& operator<<(ostream& out,const MySqQueue<T>& my)
{
	my.display(out);
	return out;
}
template <class T>
void MySqQueue<T>::randomCreate()
{
	srand((unsigned)time(NULL));
	int n=rand()%9+1;
	for(int i=1;i<=n;i++)
	{
		T a =rand()%100;
		if(enQueue(a)==ERROR)
			break;
	}
}

