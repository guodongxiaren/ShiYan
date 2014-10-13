#ifndef SQQUEUE_H
#define SQQUEUE_H
#endif
#include "myhead.h"
template<class T>
class SqQueue
{
public:
	void clear();
	Status deQueue(T& e);
	Status enQueue(T& e);
	Status getFront(T& e);
	int getLength()const;
	bool isEmpty();
	bool isFull();
	SqQueue<T>operator=(SqQueue<T> rightQ);
	SqQueue(int size=10);
	virtual ~SqQueue();
	SqQueue(const SqQueue<T>& otherQ);
protected:
	int rear;
	int front;
	int queueSize;
	T *base;
};
//clear
template<class T>
void SqQueue<T>::clear()
{
	front=rear;
}
//deQueue
template<class T>
Status SqQueue<T>::deQueue(T& e)
{
	if(isEmpty())
		return ERROR;
	e=base[front];
	front=(front+1)%queueSize;
	return OK;
}
//enQueue
template<class T>
Status SqQueue<T>::enQueue(T& e)
{
	if(isFull())
		return ERROR;
	base[rear]=e;
	rear=(rear+1)%queueSize;
	return OK;
}
//getFront
template<class T>
Status SqQueue<T>::getFront(T& e)
{
	if(isEmpty())
		return ERROR;
	e = base[front];
	return OK;
}
//getLength
template<class T>
int SqQueue<T>::getLength()const
{
	return (rear-front+queueSize)%queueSize;
}
//isEmpty
template<class T>
bool SqQueue<T>::isEmpty()
{
	return front==rear;
}
//isFull
template<class T>
bool SqQueue<T>::isFull()
{
	return (rear+1)%queueSize==front;
}

template<class T>
SqQueue<T> SqQueue<T>::operator =(SqQueue<T> rightQ)
{
	if(this!=&rightQ)
	{
		if(queueSize!=rightQ.queueSize)
		{
			delete []base;
			base = new T[rightQ.queueSize];
			assert(base!=0);
			queueSize=rightQ.queueSize;
		}
		front=rightQ.front;
		rear=rightQ.rear;
		for(int j=front;j%queueSize!=rear;)
		{
			base[j]=rightQ.base[j];
			j=(j+1)%queueSize;
		}
	}
	return *this;   
}
//*********************************************
template<class T>
SqQueue<T>::SqQueue(int size)
{
	base = new T[size];
	assert(base!=0);
	front = rear = 0;
	queueSize = size;
}
//Îö¹¹
template<class T>
SqQueue<T>::~SqQueue()
{
	delete []base;
}

template<class T>
SqQueue<T>::SqQueue(const SqQueue<T>& otherQ)
{
	base = new T[otherQ.queueSize];
	assert(base!=0);
	queueSize = otherQ.queueSize;
	front = otherQ.front;
	rear = otherQ.rear;
	for(int j = front;j%queueSize!=rear;)
	{
		base[j] = otherQ.base[j];
		j = (j+1)%queueSize;
	}
}
