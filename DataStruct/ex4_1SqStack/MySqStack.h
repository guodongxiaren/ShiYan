#ifndef MYSQSTACK_H
#define MYSQSTACK_H
#endif
#include "SqStack.h"
#include <iomanip>
template <class T>
class MySqStack:public SqStack<T>
{
public:
	void display(ostream& out)const;
	void randomCreate();
};

template <class T>
void MySqStack<T>::display(ostream& out)const
{
	cout<<"\t";
	for(T* p = base;p!=top;p++)
		cout<<setw(4)<<*p;
	cout<<endl<<"\t"<<"¡ü";
	for(T* p = base;p!=top;p++)
		cout<<"    ";
	cout<<"¡ü"<<endl<<setw(4)<<"\tbase";
	for(T* p = base;p!=top;p++)
		cout<<"    ";
	cout<<"top"<<endl;
}
template <class T>
ostream& operator<<(ostream& out,const MySqStack<T>& my)
{
	my.display(out);
	return out;
}
template <class T>
void MySqStack<T>::randomCreate()
{
	
	srand((unsigned)time(NULL));
	int n = rand()%9+1;
	base = new T[n];
	cout<<"\t";
	for(int i=1;i<=n;i++)
	{
		int e = rand()%100;
		cout<<e<<" ";
		base[i-1]= e;
	}
	cout<<endl;
	top = base+n;
}
