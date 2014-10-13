#ifndef EX4_1_TEST_H
#define EX4_1_TEST_H
#endif
#include "MySqStack.h"
////////////////////////////////////////
template <class T>
void displayCurrentObject(MySqStack<T> ms)
{
	cout<<"当前顺序栈中的元素为："<<endl;
	cout<<ms;
}
///////////////////////////////////////
template <class T>
void ex4_1_1(MySqStack<T>& ss,char& continueYesNo)
{
	cout<<" ***************在栈顶压入元素e*************"<<endl<<endl;
	T e;
	cout<<"请输入你要在栈顶压入的元素：";
	cin>>e;
	ss.push(e);
	cout<<"压入元素"<<e<<"后，新顺序栈如下所示："<<endl;
	cout<<ss;
	cout<<" ***************************************"<<endl<<endl;
	cout<<"  还继续吗(Y.继续\tN.结束)?";
	cin>>continueYesNo;
}
template <class T>
void ex4_1_2(MySqStack<T>& ss,char& continueYesNo)
{
	cout<<" ***************弹出栈顶元素到e*************"<<endl<<endl;
	T e;
		if(ss.pop(e)==ERROR)
	{
		cout<<"！栈空,不能出栈"<<endl;
		return;
	}
	cout<<"弹出的栈顶元素为："<<e<<endl;
	cout<<"弹出后顺序栈中的元素为："<<endl;
	cout<<ss;
	cout<<" ***************************************"<<endl<<endl;
	cout<<"  还继续吗(Y.继续\tN.结束)?";
	cin>>continueYesNo;
}
template <class T>
void ex4_1_3(MySqStack<T>& ss,char& continueYesNo)
{
	cout<<" ***************读栈顶元素*************"<<endl<<endl;
	T e;
	if(ss.getTop(e)==ERROR)
	{
		cout<<"！栈空，无栈顶元素"<<endl;
		return;
	}
	cout<<"读栈顶元素为："<<e<<endl;
	cout<<"读栈顶元素后，顺序栈中的元素为："<<endl;
	cout<<ss;
	cout<<" ***************************************"<<endl<<endl;
	cout<<"  还继续吗(Y.继续\tN.结束)?";
	cin>>continueYesNo;
}
template <class T>
void ex4_1_4(MySqStack<T>& ss,char& continueYesNo)
{
	cout<<" ***************判断顺序栈是否为空*************"<<endl<<endl;
	if(ss.isEmpty())
		cout<<"当前栈为空"<<endl;
	else
		cout<<"当前栈不为空"<<endl;
	cout<<" ***************************************"<<endl<<endl;
	cout<<"  还继续吗(Y.继续\tN.结束)?";
	cin>>continueYesNo;
}
template <class T>
void ex4_1_5(MySqStack<T>& ss,char& continueYesNo)
{
	cout<<" ***************求顺序栈中元素的个数*************"<<endl<<endl;
	cout<<"当前顺序栈中元素的个数为"<<ss.getLength()<<endl;
	cout<<" ***************************************"<<endl<<endl;
	cout<<"  还继续吗(Y.继续\tN.结束)?";
	cin>>continueYesNo;
}
template <class T>
void ex4_1_6(MySqStack<T>& ss,char& continueYesNo)
{
	cout<<" ***************把一个顺序栈赋值给另一个顺序栈*************"<<endl<<endl;
	MySqStack<int> t;
	t.randomCreate();
	ss=t;
	cout<<"另一个顺序栈赋值给当前顺序栈为："<<endl;
	cout<<ss;
	cout<<" ***************************************"<<endl<<endl;
	cout<<"  还继续吗(Y.继续\tN.结束)?";
	cin>>continueYesNo;
}
template <class T>
void ex4_1_7(MySqStack<T>& ss,char& continueYesNo)
{
	cout<<" ***************把顺序栈置空*************"<<endl<<endl;
	ss.clear();
	cout<<"当前顺序栈置空后，元素的个数为"<<ss.getLength()<<endl;
	cout<<" ***************************************"<<endl<<endl;
	cout<<"  还继续吗(Y.继续\tN.结束)?";
	cin>>continueYesNo;
}
template <class T>
void ex4_1_8(MySqStack<T>& ss,char& continueYesNo)
{
	cout<<" ***************随机生成顺序栈*************"<<endl<<endl;
	cout<<"随机生成的顺序站中的一些元素如下："<<endl;
	ss.randomCreate();
	cout<<endl<<"随机生成的顺序栈（采用顺序存储）如下："<<endl;
	cout<<ss;
	cout<<" ***************************************"<<endl<<endl;
	cout<<"  还继续吗(Y.继续\tN.结束)?";
	cin>>continueYesNo;
}
template <class T>
void ex4_1_9(MySqStack<T>& ss,char& continueYesNo)
{
	cout<<" ************用已有顺序栈初始化另一个新顺序栈************"<<endl<<endl;
	MySqStack<T> t(ss);
	cout<<"当前顺序栈初始化另一顺序栈为："<<endl;
	cout<<t;
	cout<<" ***************************************"<<endl<<endl;
	cout<<"  还继续吗(Y.继续\tN.结束)?";
	cin>>continueYesNo;
}
