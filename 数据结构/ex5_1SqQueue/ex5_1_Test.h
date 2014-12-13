#ifndef EX5_1_TEST_H
#define EX5_1_TEST_H
#endif
#include "MySqQueue.h"
////////////////////////////////////////
template <class T>
void displayCurrentObject(MySqQueue<T>& ms)
{
	cout<<"当前顺序栈中的元素为："<<endl;
	cout<<ms;
}
///////////////////////////////////////
template <class T>
void ex5_1_1(MySqQueue<T>& ss,char& continueYesNo)
{
	cout<<" ***************在队首插入元素e*************"<<endl<<endl;
	T e;
	cout<<"请输入你要在队首插入的元素：";
	cin>>e;
	if(ss.enQueue(e)==ERROR)
	{
		cout<<"队满！"<<endl;
		return;
	}
	cout<<"插入元素"<<e<<"后，新顺序队列如下所示："<<endl;
	cout<<ss;
	cout<<" ***************************************"<<endl<<endl;
	cout<<"  还继续吗(Y.继续\tN.结束)?";
	cin>>continueYesNo;
}
template <class T>
void ex5_1_2(MySqQueue<T>& ss,char& continueYesNo)
{
	cout<<" ***************弹出队尾元素到e*************"<<endl<<endl;
	T e;
		if(ss.deQueue(e)==ERROR)
	{
		cout<<"！栈空,不能出队列"<<endl;
		return;
	}
	cout<<"弹出的队尾元素为："<<e<<endl;
	cout<<"弹出后顺序队列中的元素为："<<endl;
	cout<<ss;
	cout<<" ***************************************"<<endl<<endl;
	cout<<"  还继续吗(Y.继续\tN.结束)?";
	cin>>continueYesNo;
}
template <class T>
void ex5_1_3(MySqQueue<T>& ss,char& continueYesNo)
{
	cout<<" ***************读队首元素*************"<<endl<<endl;
	T e;
	if(ss.getFront(e)==ERROR)
	{
		cout<<"！队空，无队首元素"<<endl;
		return;
	}
	cout<<"读队首元素为："<<e<<endl;
	cout<<"读队首元素后，顺序队列中的元素为："<<endl;
	cout<<ss;
	cout<<" ***************************************"<<endl<<endl;
	cout<<"  还继续吗(Y.继续\tN.结束)?";
	cin>>continueYesNo;
}
template <class T>
void ex5_1_4(MySqQueue<T>& ss,char& continueYesNo)
{
	cout<<" ***************判断顺序队列是否为空*************"<<endl<<endl;
	if(ss.isEmpty())
		cout<<"当前队列为空"<<endl;
	else
		cout<<"当前队列不为空"<<endl;
	cout<<" ***************************************"<<endl<<endl;
	cout<<"  还继续吗(Y.继续\tN.结束)?";
	cin>>continueYesNo;
}

/////////////////////////////////////
template <class T>
void ex5_1_5(MySqQueue<T>& ss,char& continueYesNo)
{
	cout<<" ***************判断循环队列是否满*************"<<endl<<endl;
	if(ss.isFull())
		cout<<"循环队列已满"<<endl;
	else
		cout<<"循环队列没满"<<endl;
	cout<<" ***************************************"<<endl<<endl;
	cout<<"  还继续吗(Y.继续\tN.结束)?";
	cin>>continueYesNo;
}
template <class T>
void ex5_1_6(MySqQueue<T>& ss,char& continueYesNo)
{
	cout<<" ***************求顺序队列中元素的个数*************"<<endl<<endl;
	cout<<"当前顺序队列中元素的个数为"<<ss.getLength()<<endl;
	cout<<" ***************************************"<<endl<<endl;
	cout<<"  还继续吗(Y.继续\tN.结束)?";
	cin>>continueYesNo;
}
template <class T>
void ex5_1_7(MySqQueue<T>& ss,char& continueYesNo)
{
		cout<<" ***************把一个顺序队列赋值给另一个顺序队列*************"<<endl<<endl;
	MySqQueue<int> t;
	t.randomCreate();
	ss=t;
	cout<<"另一个顺序队列赋值给当前顺序队列为："<<endl;
	cout<<ss;
	cout<<" ***************************************"<<endl<<endl;
	cout<<"  还继续吗(Y.继续\tN.结束)?";
	cin>>continueYesNo;
}
template <class T>
void ex5_1_8(MySqQueue<T>& ss,char& continueYesNo)
{
	cout<<" ***************把顺序队列置空*************"<<endl<<endl;
	ss.clear();
	cout<<"当前顺序队列置空后，元素的个数为"<<ss.getLength()<<endl;
	cout<<" ***************************************"<<endl<<endl;
	cout<<"  还继续吗(Y.继续\tN.结束)?";
	cin>>continueYesNo;
}
template <class T>
void ex5_1_9(MySqQueue<T>& ss,char& continueYesNo)
{
	cout<<" ***************随机生成顺序队列*************"<<endl<<endl;
	cout<<"随机生成的顺序站中的一些元素如下："<<endl;
	ss.randomCreate();
	cout<<endl<<"随机生成的顺序栈（采用顺序存储）如下："<<endl;
	cout<<ss;
	cout<<" ***************************************"<<endl<<endl;
	cout<<"  还继续吗(Y.继续\tN.结束)?";
	cin>>continueYesNo;
}
template <class T>
void ex5_1_10(MySqQueue<T>& ss,char& continueYesNo)
{
	cout<<" ************用已有顺序队列初始化另一个新顺序队列************"<<endl<<endl;
	MySqQueue<T> t(ss);
	cout<<"当前顺序队列初始化另一顺序队列为："<<endl;
	cout<<t;
	cout<<" ***************************************"<<endl<<endl;
	cout<<"  还继续吗(Y.继续\tN.结束)?";
	cin>>continueYesNo;
}