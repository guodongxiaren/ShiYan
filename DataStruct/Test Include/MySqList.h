/////////////////////////////////////////////////
//MySqList.h顺序表数据结构C++类定义（派生类）
/////////////////////////////////////////////////
#ifndef SQLIST_H
	#define SQLIST_H
	#include "e:\wangwei\Include\SqList.h"
#endif
#include <iomanip>
//顺序表数据结构C++类声明（派生类）
template <typename ElemType>
class MySqList:public SqList<ElemType>
{
public:
	void read(istream& in);
	void display(ostream& out)const;
	void randCreate();
};

//输入顺序表
template <typename ElemType>
void MySqList<ElemType>::read(istream& in)
{
	cout<<"输入顺序表中元素的个数"<<endl;
	cin>>n;
	cout<<"输入"<<n<<"个元素的值:";
	for(int i=1;i<=n;i++)
	{
		cin>>elem[i-1];
	}
}
//>>重载
template <typename ElemType>
istream& operator>>(istream& in,MySqList<ElemType>& sq)
{
	sq.read(in);
	return in;
}
template <typename ElemType>
void MySqList<ElemType>::display(ostream& out)const
{
	int line=n/10+1;//每行显示10个，共有line行
	int i=1,j=1;
	while(line--)//因为输出可能会折行，所以一行一行显示
	{
	for(;i%11&&i<=n;i++)
		out<<"["<<setw(2)<<i<<"] ";
	out<<endl;
	for(;j%11&&j<=n;j++)
	{
		out<<setw(4)<<elem[j-1]<<" ";
	}
	cout<<endl;		
	}
}
template <typename ElemType>
ostream& operator<< (ostream& out,const MySqList<ElemType>& oD)
{
	oD.display(out);
	return out;
}
template <typename ElemType>
void MySqList<ElemType>::randCreate()
{
	srand((unsigned)time(NULL));
	n = rand()%10+1;
	for(int i=1;i<=n;i++)
	{
		elem[i-1]=rand()%100;
	}
}
//并集
template <typename ElemType>
 MySqList<ElemType> unionSet
	 (MySqList<ElemType> firstL,MySqList<ElemType> secondL)
{
	ElemType e;
	MySqList<ElemType> thirdL(firstL);
	for(int i=1;i<=secondL.getLength();++i)
	{
		secondL.getElem(i,e);
		if(!firstL.locateElem(e,equal))
		{
			thirdL.insert(thirdL.getLength()+1,e);
		}
	}
	return thirdL;
}
 //交集
 template <typename ElemType>
 MySqList<ElemType> intersectionSet
	 (MySqList<ElemType> firstL,MySqList<ElemType> secondL)
 {
	 int k=0;
	 ElemType e;
	 MySqList<ElemType> thirdL;
	 for(int i=1;i<=firstL.getLength();++i)
	 {
		 firstL.getElem(i,e);
		 if(secondL.locateElem(e,equal))
		 {
			 thirdL.insert(++k,e);
		 }
	 }
	 return thirdL;
 }
 //差集
 template<typename ElemType>
 MySqList<ElemType> dirfferenceSet
	 (MySqList<ElemType> firstL,MySqList<ElemType> secondL)
 {
	 int k=0;
	 ElemType e;
	 MySqList<ElemType> thirdL;
	 for(int i=1;i<=firstL.getLength();++i)
	 {
		 firstL.getElem(i,e);
		 if(!secondL.locateElem(e,equal))
		 {
			 thirdL.insert(++k,e);
		 }
	 }
	 return thirdL;
 }