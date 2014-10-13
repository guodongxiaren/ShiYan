#ifndef MYHEAD_H
#define MYHEAD_H
#include "e:\wangwei\Include\myhead.h"
#endif
////////////////////////////////////////////////
//非循环单链表数据结构C++类声明（基类）
///////////////////////////////////////////////
template <typename ElemType>
class LinkList
{
public:
	class LinkNode
	{
	public:
		ElemType data;
		LinkNode *next;
	};
	typedef LinkNode * NodePointer;
	//非循环单链表的逆置
	void adverse();
	//非循环单链表置空
	void clear();
	//删除非循环单链表中数据域为e的第一个结点
	Status deleteElem(ElemType e);
	//删除非循环单链表中的重复值
	void deleteRepeat();
	//取非循环单链表的第i个结点
	Status getElem(int i,ElemType& e);
	//取第一个结点的指针
	NodePointer getHead();
	//求非循环单链表的结点的个数
	int getLength();
	//在第i个结点之前插入一个数据域为e的结点
	Status insert(int i,ElemType e);
	//判断非循环单链表是否为空
	bool isEmpty();
	//查找第1个与e满足compare关系的结点
	Status locateElem(ElemType e,Status (*compare)(ElemType,ElemType),int &i);
	//返回某结点后继的数据域
	Status nextElem(ElemType e,ElemType& next_e);
	//重载运算符的定义
	LinkList<ElemType> operator=(LinkList<ElemType> rightL);
	//返回某结点前驱的数据域
	Status priorElem(ElemType e,ElemType& prior_e);
	//*******************系统自动调用的构造及析构函数*********************
	LinkList();
	virtual ~LinkList();
	//拷贝初始化构造函数
	LinkList(const LinkList<ElemType>& otherL);
protected:
	NodePointer head;
};
//非循环单链表的逆置
template <typename ElemType>
void LinkList<ElemType>::adverse()
{
	NodePointer r,p,q;
	if(!head)
		return;
	r = 0,p = head,q = p->next;
	while(p)
	{
		p->next = r;
		r = p;
		p = q;
		if(q)
			q = q->next;
	}
	head = r;
}
//非循环单链表的置空
template <typename ElemType>
void LinkList<ElemType>::clear()
{
	NodePointer p,q;
	p = 0,q = head;
	while(q)
	{
		p = q;
		q = q->next;
		delete p;
	}
	head = 0;
}
//删除非循环单链表中数据域为e的第一个结点
template <typename ElemType>
Status LinkList<ElemType>::deleteElem(ElemType e)
{
	NodePointer r,p;
	r = 0,p = head;
	while(p&&!equal(p->data,e))
	{
		r = p;
		p = p->next;
	}
	if(p==0)
		return ERROR;
	if(r==0)
		head=head->next;
	else
		r->next = p->next;
	delete p;
	return OK;
}
//删除重复值
template <typename ElemType>
void LinkList<ElemType>::deleteRepeat()
{
	NodePointer r,p,s;
	r = 0,p = head;
	while(p)
	{
		s = head;
		while(s!=p)
		{
			if(s->data==p->data)
			{
				r->next = p->next;
				delete p;
				p = r;
				break;//先前比较的每一步都能保证不再用重复值
			}
			s=s->next;
		}
		r = p;
		if(p)
			p=p->next;
	}
}
//取非循环单链表的第i个结点
template <typename ElemType>
Status LinkList<ElemType>::getElem(int i,ElemType& e)
{
	int j=1;
	NodePointer p = head;
	while(p&&j<i)
	{
		p = p->next;
		++j;
	}
	if(!p||j>i)
		return ERROR;
	e = p->data;
	return OK;
}
//取第一个结点的指针
template <typename ElemType>
typename LinkList<ElemType>::NodePointer LinkList<ElemType>::getHead()
{
	return head;
}
//求非循环单链表的结点的个数
template <typename ElemType>
int LinkList<ElemType>::getLength()
{
	int n = 0;
	NodePointer p = head;
	while(p)
	{
		++n;
		p = p->next;
	}
	return n;
}
//在第i个结点之前插入一个数据域为e的结点
template <typename ElemType>
Status LinkList<ElemType>::insert(int i,ElemType e)
{
	int j = 1;
	NodePointer p = head;
	NodePointer s;

	while(p&&j<i-1)
	{
		++j;
		p = p->next;
	}
	if(!p||j>i)
		return ERROR;
	s = new LinkNode;
	assert(s!=0);
	s->data = e;
	if(i==1)
	{
		s->next = p->next;
		head = s;
	}
	else
	{
		s->next = p->next;
		p->next = s;
	}
	return OK;
}
//判断是否为空
template <typename ElemType>
bool LinkList<ElemType>::isEmpty()
{
	return head?false:true;
}
//查找第1个与e满足compare关系的结点
template <typename ElemType>
Status LinkList<ElemType>::locateElem(ElemType e,Status (*compare)(ElemType,ElemType),int &i)
{
	NodePointer p = head;
	i = 1;
	while(p&&!(*compare)(p->data,e))
	{
		p = p->next;
		i++;
	}
	if(!p)
		return ERROR;
	return OK;
}

template<typename ElemType>
Status LinkList<ElemType>::nextElem(ElemType e, ElemType& next_e)
{
	NodePointer p = head;
	while(p&&!equal(p->data,e))
		p = p->next;
	if(!p||!p->next)
		return ERROR;
	next_e = p->next->data;
	return OK;
}

template<typename ElemType>
LinkList<ElemType> LinkList<ElemType>::operator =(
	LinkList<ElemType> rightL)
{
	NodePointer p = 0;
	NodePointer rp = rightL.getHead();
	NodePointer s;
	//判断左边的单链表是否等于右边的rightL
	if(this!=&rightL)
	{
		clear();
		while(rp)
		{
			s = new LinkNode;
			assert(s!=0);
			s->data = rp->data;
			if(!head)
				head = s;
			else
				p->next = s;
			p = s;
			rp = rp->next;
		}
		if(p)
			p->next = 0;
	}
	return *this;
}

template<typename ElemType>
Status LinkList<ElemType>::priorElem(ElemType e, ElemType& prior_e)
{
	NodePointer r = 0;
	NodePointer p = head;
	while(p&&!equal(p->data,e))
	{
		r = p;
		p = p->next;
	}
	if(!p||!r)
		return ERROR;
	prior_e = r->data;
	return OK;
}

template<typename ElemType>
LinkList<ElemType>::LinkList()
{
	head = NULL;
}

template<typename ElemType>
LinkList<ElemType>::~LinkList()
{
	clear();
}

template<typename ElemType>
LinkList<ElemType>::LinkList(const LinkList<ElemType>& otherL)
{
	NodePointer p;
	NodePointer op = otherL.head;
	NodePointer s;
	head = p = 0;
	//复制otherL的每个结点
	while(op)
	{
		s = new LinkNode;
		assert(s!=0);
		s->data = op->data;
		if(!head)
			head = s;
		else
			p->next = s;
		p = s;
		op = op->next;
	}
	if(head)
		p->next = 0;
}
