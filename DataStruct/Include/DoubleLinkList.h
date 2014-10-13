#ifndef MYHEAD_H
#define MYHEAD_H
#include "e:\wangwei\Include\myhead.h"
#endif
template <typename ElemType>
class DoubleLinkList
{
public:
	struct LinkNode
	{
		ElemType data;
		LinkNode *next;
		LinkNode *prior;
	};
	typedef LinkNode* NodePointer;
	void clear();
	Status deleteElem(ElemType e);
	Status getElem(int i,ElemType& e);
	NodePointer getHead();
	int getLength()const;
	Status insert(int i,ElemType e);
	bool isEmpty();
	Status locateElem(ElemType find_e,NodePointer& r);
	Status nextElem(ElemType e,ElemType& next_e);
	DoubleLinkList<ElemType> operator=(DoubleLinkList<ElemType>rightL);
	Status priorElem(ElemType e,ElemType& prior_e);
	//*******************************************
	DoubleLinkList();
	virtual ~DoubleLinkList();
	DoubleLinkList(const DoubleLinkList<ElemType>& otherL);

protected:
	NodePointer head;
};
//
template <typename ElemType>
void DoubleLinkList<ElemType>::clear()
{
	NodePointer r,p;
	if(!head)
		return;
	p=head->prior;
	while(p!=head)
	{
		r = p->prior;
		delete p;
		p = r;
	}
	delete p;
	head = 0;
}
template <typename ElemType>
Status DoubleLinkList<ElemType>::deleteElem(ElemType e)
{
	NodePointer p;
	if(!locateElem(e,p))
		return ERROR;
	if(head->next == head)
	{
		delete head;
		head = 0;
	}
	else
	{
		if(p==head)
			head = p->next;
		p->prior->next = p->next;
		p->next->prior = p->prior;
	}
	delete p;
	return OK;
}
template <typename ElemType>
Status DoubleLinkList<ElemType>::getElem(int i,ElemType& e)
{
	int j = 1;
	if(!this->getLength())
		return ERROR;
	NodePointer p = head;
	while(p&&p->next!=head&&j<i)
	{
		p = p->next;
		j++;
	}
	if(j==i)
	{
		e = p->data;
		return OK;
	}
	return ERROR;
}
template <typename ElemType>
typename DoubleLinkList<ElemType>::NodePointer DoubleLinkList<ElemType>::getHead()
{
	return head;
}
template <typename ElemType>
int DoubleLinkList<ElemType>::getLength()const
{
	int length=0;
	NodePointer p = head;
	while(p)
	{
		++length;
		p = p->next;
		if(p==head)
			break;
	}
	return length;
}
template <typename ElemType>
Status DoubleLinkList<ElemType>::insert(int i,ElemType e)
{
	int j = 1;
	NodePointer p = head;
	NodePointer s;
	while(p&&p->next!=head&&j<i)
	{
		p=p->next;
		++j;
	}
	if(!head&&i!=1||j<i-1)//比如有6个元素那么插入7的位置也是合法的，所以j<i-1才是不合法情况
		return ERROR;
	s = new LinkNode;
	assert(s!=0);
	s->data = e;
	if(i==1)
	{
		if(!head)
		{
			head = s->prior = s->next = s;
			return OK;
		}
		head = s;
	}
	p->prior->next = s;
	s->prior = p->prior;
	p->prior = s;
	s->next = p;
	return OK;
}
template <typename ElemType>
bool DoubleLinkList<ElemType>::isEmpty()
{
	return head?false:true;
}
template <typename ElemType>
Status DoubleLinkList<ElemType>::locateElem(ElemType e,NodePointer& r)
{
	NodePointer p = head;
	while(p&&p->next!=head&&p->data!=e)
		p=p->next;
	if(p->data==e)
	{
		r = p;
		return OK;
	}
	else
		return ERROR;
}
template <typename ElemType>
Status DoubleLinkList<ElemType>::nextElem(ElemType e,ElemType& next_e)
{
	NodePointer p;
	if(locateElem(e,p))
	{
		next_e = p->next->data;
		return OK;
	}
	else
		return ERROR;
}
template <typename ElemType>
DoubleLinkList<ElemType> DoubleLinkList<ElemType>::operator=(DoubleLinkList<ElemType> rightL)
{
	NodePointer p = 0;
	NodePointer rp = rightL.getHead();
	NodePointer s;
	if(this!=&rightL)
	{
		clear();
		while(rp)
		{
			s = new LinkNode;
			assert(s!=0);
			s->data =  rp->data;
			if(!head)
				head = p = s;
			p->next = s;
			s->prior = p;

			p = s;
			rp = rp->next;
			if(rp==rightL.head)
				break;
		}
		if(head)
		{
			head->prior = p;
			p->next = head;
		}
	}
	return *this;
}
template <typename ElemType>
Status DoubleLinkList<ElemType>::priorElem(ElemType e,ElemType& prior_e)
{
	NodePointer p;
	if(locateElem(e,p))
	{
		prior_e = p->prior->data;
		return OK;
	}
	return ERROR;
}
////************************************
template <typename ElemType>
DoubleLinkList<ElemType>::DoubleLinkList()
{
	head = 0;
}
template <typename ElemType>
DoubleLinkList<ElemType>::~DoubleLinkList()
{
	clear();
}
template <typename ElemType>
DoubleLinkList<ElemType>::DoubleLinkList(const DoubleLinkList& otherL)
{
	NodePointer p;
	NodePointer op = otherL.head;
	NodePointer s;
	head = p = 0;

	while(op)
	{
		s = new LinkNode;
		assert(s!=0);
		s->data = op->data;
		if(!head)
			head = p = s;
		p->next = s;
		s->prior = p;
		p = s;
		op = op->next;
		if(op==otherL.head)
			break;
	}
	if(head)
	{
		head->prior = p;
		p->next = head;
	}
}
