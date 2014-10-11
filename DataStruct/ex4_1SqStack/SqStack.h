/////////////////////////////////////////
//SqStack.h 顺序栈数据结构C++类定义
/////////////////////////////////////////
#ifndef SQSTACK_H
#define SQSTACK_H
#endif
#include "myhead.h"
#define STACK_MAX_SIZE 100
#define STACKINCREMENT 10
/////////////////////////////////////////
template <class T>
class SqStack
{
public:
	void clear();
	int getLength();
	int getstackSize();
	Status getTop(T &e);
	bool isEmpty();
	SqStack<T> operator=(SqStack<T> rightS);
	Status pop(T &e);
	void push(T e);
	//////////////////////////////////////
	SqStack();
	virtual ~SqStack();
	SqStack(const SqStack<T>& otherS);
protected:
	T *base;
	T *top;
	int stackSize;
};
//clear
template <class T>
void SqStack<T>::clear()
{
	top = base;
}
//getLength
template <class T>
int SqStack<T>::getLength()
{
	return top-base;
}
//getstackSize
template <class T>
int SqStack<T>::getstackSize()
{
	return stackSize;
}
//getTop
template <class T>
Status SqStack<T>::getTop(T& e)
{
	if(isEmpty())
		return ERROR;
	else
		e = *(top-1);
	return OK;
}
//isEmpty
template <class T>
bool SqStack<T>::isEmpty()
{
	return top==base;
}
//operator =
template <class T>
typename SqStack<T> SqStack<T>::operator=(SqStack rightS)
{
	int length = rightS.getLength();
	if(this!=&rightS)
	{
		if(stackSize<rightS.stackSize)
		{
			delete[] base;
			base = new T[rightS.stackSize];
			assert(base!=0);
			stackSize = rightS.stackSize;
		}
		for(int i=0;i<length;i++)
			*(base+i)=*(rightS.base+i);
		top = base + length;
	}
	return *this;
}
//pop
template <class T>
Status SqStack<T>::pop(T& e)
{
	if(isEmpty())
		return ERROR;
	else
		e = *--top;
	return OK;
}
//push
template <class T>
void SqStack<T>::push(T e)
{
	int length = top-base;
	T* newbase;
	if(top-base>=stackSize)
	{
		newbase = new T[stackSize+STACKINCREMENT];
		assert(newbase!=0);
		for(int j=0;j<length;j++)
			*(newbase+j)=*(base+j);
		delete[] base;
		stackSize+=STACKINCREMENT;
		base = newbase;
		top = base+length;
	}
	*top = e;
	++top;
}
//SqStack()
template <class T>
SqStack<T>::SqStack()
{
	base = new T[STACK_MAX_SIZE];
	assert(base!=0);
	stackSize = STACK_MAX_SIZE;

	top = base;
}
//~SqStack
template <class T>
SqStack<T>::~SqStack()
{
	if(base)
		delete []base;
	stackSize = 0;
	stackSize = 0;
	top = base = 0;
}
//copy
template <class T>
SqStack<T>::SqStack(const SqStack& otherS)
{
	int length=otherS.top-otherS.base;
	base = new T[otherS.stackSize];
	assert(base!=0);

	stackSize = otherS.stackSize;
	for(int i = 0;i<length;i++)
		*(base+i)=*(otherS.base+i);
	top=base+length;
}