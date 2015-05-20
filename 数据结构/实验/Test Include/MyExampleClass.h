/////////////////////////////////////////////////
//MyExampleClass.h长方形数据结构C++类定义（派生类）
/////////////////////////////////////////////////
#ifndef EXAMPLECLASS_H
	#define EXAMPLECLASS_H
	#include "E:\wangwei\Include\ExampleClass.h"
#endif
//长方形数据结构C++类声明（派生类）
template <typename ElemType>
class MyRectangle:public Rectangle<ElemType>
{
public:
	void read(istream& in);
	void display(ostream& out)const;
};
/*
实现部分
*/
//功能：输入长方形的信息
template <typename ElemType>
void MyRectangle<ElemType>::read(istream& in)
{
	cout<<"    请输入第"<<myNo.no<<"个长方形对象"<<endl;
	cout<<"        长方形中的长：";
	in>>length;
	cout<<"        长方形中的宽：";
	in>>width;
}
//重载>>符号
template <typename ElemType>
istream& operator >>(istream& in,MyRectangle<ElemType>& iD)
{
	iD.read(in);
	return in;
}
//功能：输出长方形信息
template <typename ElemType>
void MyRectangle<ElemType>::display(ostream& out)const
{
	out<<"    第"<<myNo.no<<"个长方形对象 长 = "<<length<<"\t 宽 = "
		<<width<<endl;
}
//重载<<符号
template <typename ElemType>
ostream& operator<< (ostream& out,const MyRectangle<ElemType>& oD)
{
	oD.display(out);
	return out;
}
