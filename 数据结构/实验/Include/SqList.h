#ifndef MYHEAD_H
#define MYHEHD_H
#include "E:\wangwei\Include\myhead.h"
#endif
//常量
#define LIST_MAX_SIZE 100
#define LISTINCREMENT 10

template <typename ElemType>
class SqList
{
public:
	//清空
	void clear();
	//删除第i个元素
	Status deleteElem(int i,ElemType& e);
	//取第i个元素
	Status getElem(int i,ElemType& e);
	//求顺序表中元素个数
	int getLength();
	//取顺序表存储空间的大小
	int getListSize();
	//在第i个元素之前插入一个元素
	Status insert(int i,ElemType& e);
	//判断顺序表是否为空
	bool isEmpty();
	//查找第1个与e满足compare()关系的元素的序号
	int locateElem(ElemType e,Status (*compare)(ElemType,ElemType));
	//返回某元素的后继
	Status nextElem(ElemType e,ElemType& next_e);
	//重载赋值运算符的定义
	SqList<ElemType> operator=(SqList<ElemType> rightL);
	//返回某元素的前驱
	Status priorElem(ElemType e,ElemType& prior_e);
	//在顺序表中数学查找某元素
	int sequentialSearch(ElemType e);
	//*********//
	SqList();
	virtual ~SqList();
	SqList(const SqList<ElemType>& otherL);
protected:
	ElemType *elem;
	int listSize;
	int n;
};
//*************//
template<typename ElemType>
SqList<ElemType>::SqList()
{
	elem = new ElemType[LIST_MAX_SIZE];
	assert(elem!=0);
	listSize = LIST_MAX_SIZE;
	n = 0;
}
//析构函数
template<typename ElemType>
SqList<ElemType>::~SqList()
{
	delete[] elem;
	listSize = 0;
	n = 0;
}
//拷贝初始化构造函数
template<typename ElemType>
SqList<ElemType>::SqList(const SqList<ElemType>& otherL)
{
	elem = new ElemType[otherL.listSize];
	assert(elem!=0);
	listSize = otherL.listSize;
	n = otherL.n;
	
	for(int i=0;i<n;i++)
		elem[i]=otherL.elem[i];
}

//清空
template<typename ElemType>
void SqList<ElemType>::clear()
{
	n = 0;
}
//删除第i个元素
template<typename ElemType>
Status SqList<ElemType>::deleteElem(int i,ElemType& e)
{
	if(i<1||i>n)
		return ERROR;
	e = elem[i-1];
	for(int j=i+1;j<=n;j++)
		elem[j-2] = elem[j-1];
	--n;
	return OK;
}
//取第i个元素
template<typename ElemType>
Status SqList< ElemType>::getElem(int i,ElemType& e)
{
	if(i>n||i<1)
		return ERROR;
	e = elem[i-1];
	return OK;
}
//求顺序表中元素个数
template<typename ElemType>
int SqList<ElemType>::getLength()
{
	return n;
}
//取顺序表存储空间的大小
template<typename ElemType>
int SqList<ElemType>::getListSize()
{
	return listSize;
}
//在第i个元素之前插入一个元素
template<typename ElemType>
Status SqList<ElemType>::insert(int i,ElemType& e)
{
	ElemType *newbase;
	
	if(i<1||i>n+1)
		return ERROR;
	//
	if(n>=listSize)
	{
		newbase = new ElemType[listSize+LISTINCREMENT];
		assert(newbase!=0);
		for(int j=1;j<=n;j++)
			newbase[j-1]=elem[j-1];
		delete[] elem;
		elem=newbase;
		listSize+=LISTINCREMENT;
	}
	//从顺序表的最后一个元素开始，直到第i个元素，每个元素后移一位
	for(int j=n;j>=i;j--)
		elem[j]=elem[j-1];
	elem[i-1]=e;
	++n;
	return OK;
}

//判断顺序表是否为空
template <typename ElemType>
bool SqList<ElemType>::isEmpty()
{
	return n?false:true;
}
//查找第1个与e满足compare()关系的元素的序号
template <typename ElemType>
int SqList<ElemType>::locateElem(ElemType e,Status (*compare)(ElemType,ElemType))
{
	int i;
	for(i=1;i<=n&&!(*compare)(elem[i-1],e);++i);
		if(i<=n)
			return i;
		else
			return 0;
}
//返回某元素的后继
template <typename ElemType>
Status SqList<ElemType>::nextElem(ElemType e,ElemType& next_e)
{
	int i=locateElem(e,equal);
	if(i<1||i==n)
		return ERROR;
	else
		getElem(i+1,next_e);
	return OK;
}
//重载赋值运算符的定义
template <typename ElemType>
SqList<ElemType> SqList<ElemType>::operator=(SqList<ElemType> rightL)
{
	if(this!=&rightL)
	{
		if(listSize<rightL.listSize)
		{
			delete[] elem;
			elem = new ElemType[rightL.listSize];
			
			assert(elem!=0);
			listSize = rightL.listSize;
		}
		n = rightL.n;
		for(int i=1;i<=n;i++)
			elem[i-1]=rightL.elem[i-1];
	}
	return *this;
}
//返回某元素的前驱
template <typename ElemType>
Status SqList<ElemType>::priorElem(ElemType e,ElemType& prior_e)
{
	int i=locateElem(e,equal);
	if(i<=1)
		return ERROR;
	else
		getElem(i-1,prior_e);
	return OK;
}
//在顺序表中数学查找某元素
template <typename ElemType>
int SqList<ElemType>::sequentialSearch(ElemType key)
{
	for(int i=1;i<=n&&key!=elem[i-1];++i);
	if(i<=n)
		return i;
	else
		return 0;
}