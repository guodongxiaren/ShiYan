#ifndef MYDOUBLELINKLIST_H
#define MYDOUBLELINKLIST_H
#include "e:\wangwei\Test Include\MyDoubleLinkList.h"

#endif
template <typename ElemType>
void displayCurrentObject(MyDoubleLinkList<ElemType>& dll)
{
	cout<<"当前循环双链表为："<<endl<<endl;
	cout<<dll;
}
template <typename ElemType>
void ex3_4_1(MyDoubleLinkList<ElemType>& link,char& continueYesNo)
{
	int i;
	ElemType e;
	cout<<"************\4取循环双链表的第i个结点\4************"<<endl<<endl;
	cout<<"请输入你要取的结点的序号：";
	cin>>i;
	if(link.getElem(i,e)==ERROR)
		cout<<"错误!该链表中没有第"<<i<<"的结点"<<endl;
	else
	    cout<<"你要取非循环单链表的第"<<i<<"个结点的数据域为"<<e<<endl<<endl;

	cout<<" ***************************************"<<endl<<endl;
	cout<<"  还继续吗(Y.继续\tN.结束)?";
	cin>>continueYesNo;
}
template <typename ElemType>
void ex3_4_2(MyDoubleLinkList<ElemType>& link,char& continueYesNo)
{
	int i;
	ElemType e;
	cout<<"**********\4在第i个结点之前插入一个数据域为e的结点\4*********"<<endl<<endl;
	cout<<"请输入你要在它之前插入结点的序号：";
	cin>>i;
	cout<<"请输入你要插入结点的数据域：";
	cin>>e;
	if(link.insert(i,e)==ERROR)
		cout<<"错误!该链表中没有第"<<i<<"的结点"<<endl;
	else
	{
		cout<<endl<<"你已经在第"<<i<<"个结点之前插入数据域为"<<e<<"的结点"<<endl;
		cout<<link;
	}
	cout<<" ***************************************"<<endl<<endl;
	cout<<"  还继续吗(Y.继续\tN.结束)?";
	cin>>continueYesNo;
}
template <typename ElemType>
void ex3_4_3(MyDoubleLinkList<ElemType>& link,char& continueYesNo)
{
	cout<<"************\4判断循环双链表是否为空\4************"<<endl<<endl;
	printf("当前循环双链表链表%s\n",link.isEmpty()?"为空":"不为空");
	cout<<" ***************************************"<<endl<<endl;
	cout<<"  还继续吗(Y.继续\tN.结束)?";
	cin>>continueYesNo;
}
template <typename ElemType>
void ex3_4_4(MyDoubleLinkList<ElemType>& link,char& continueYesNo)
{
	cout<<"************\4求循环双链表中结点的个数\4************"<<endl<<endl;
	cout<<"非循环单链表中结点的个数为："<<link.getLength()<<endl;
	cout<<" ***************************************"<<endl<<endl;
	cout<<"  还继续吗(Y.继续\tN.结束)?";
	cin>>continueYesNo;
}
template <typename ElemType>
void ex3_4_5(MyDoubleLinkList<ElemType>& link,char& continueYesNo)
{
		cout<<"************\4返回循环双链表中数据域为e的第一个结点的指针\4************"<<endl<<endl;
		ElemType e;
		cout<<"\t请输入你想要查找结点的数据域为：";
		cin>>e;
		DoubleLinkList<ElemType>::NodePointer r;
		if(link.locateElem(e,r)==ERROR)
		cout<<"该链表中没有数据域为"<<e<<"的结点"<<endl;
		else
			cout<<"你想查找第一个数据域等于"<<e<<"的结点的数据域为"<<r->data<<endl;
	cout<<" ***************************************"<<endl<<endl;
	cout<<"  还继续吗(Y.继续\tN.结束)?";
	cin>>continueYesNo;
}
template <typename ElemType>
void ex3_4_6(MyDoubleLinkList<ElemType>& link,char& continueYesNo)
{
	ElemType e,prior_e;
	cout<<"************\4返回某结点前驱的数据域\4************"<<endl<<endl;
	cout<<"请输入你想查找结点的数据域：";
	cin>>e;
	if(link.priorElem(e,prior_e)==ERROR)
		cout<<"错误！该链表中无此结点或者该结点为头结点"<<endl;
	else
		cout<<"你想查找"<<e<<"前驱的数据域为"<<prior_e<<endl<<endl;
	cout<<" ***************************************"<<endl<<endl;
	cout<<"  还继续吗(Y.继续\tN.结束)?";
	cin>>continueYesNo;
}
template <typename ElemType>
void ex3_4_7(MyDoubleLinkList<ElemType>& link,char& continueYesNo)
{
	ElemType e,next_e;
	cout<<"************\4返回某结点后继的数据域\4************"<<endl<<endl;
	cout<<"请输入你想查找结点的数据域：";
	cin>>e;
	if(link.nextElem(e,next_e)==ERROR)
		cout<<"错误！该链表中无此结点或者该结点为尾结点"<<endl;
	else
		cout<<"你想查找"<<e<<"后继的数据域为"<<next_e<<endl<<endl;
	cout<<" ***************************************"<<endl<<endl;
	cout<<"  还继续吗(Y.继续\tN.结束)?";
	cin>>continueYesNo;
}
template <typename ElemType>
void ex3_4_8(MyDoubleLinkList<ElemType>& link,char& continueYesNo)
{
		ElemType e;
	cout<<"*********\4删除循双单链表中数据域为e的第一个结点\4********"<<endl;
	cout<<"请输入你想删除结点的数据域：";
	cin>>e;
	if(link.deleteElem(e)==ERROR)
		cout<<"错误!该链表中无此结点"<<endl;
	else
	{
		cout<<endl<<"删除后循环双链表为"<<endl;
		cout<<link;
	}
	cout<<" ***************************************"<<endl<<endl;
	cout<<"  还继续吗(Y.继续\tN.结束)?";
	cin>>continueYesNo;
}
template <typename ElemType>
void ex3_4_9(MyDoubleLinkList<ElemType>& link,char& continueYesNo)
{
	cout<<"*********\4把一个循环双链表赋值给另一个循环双链表\4**********"<<endl;
	MyDoubleLinkList<int> otherL;
	otherL.randCreate();
	link=otherL;
	cout<<endl<<"另一个循环双链表赋值给当前循环双链表为："<<endl;
	cout<<link;
	cout<<" ***************************************"<<endl<<endl;
	cout<<"  还继续吗(Y.继续\tN.结束)?";
	cin>>continueYesNo;
}
template <typename ElemType>
void ex3_4_10(MyDoubleLinkList<ElemType>& link,char& continueYesNo)
{
	cout<<"*************\4把循环双链表置空\4*****************"<<endl;
	link.clear();
	cout<<endl<<"当前非循环单链表置空后，数据元素的个数为："<<link.getLength()<<endl<<endl;
	cout<<" ***************************************"<<endl<<endl;
	cout<<"  还继续吗(Y.继续\tN.结束)?";
	cin>>continueYesNo;
}
template <typename ElemType>
void ex3_4_11(MyDoubleLinkList<ElemType>& link,char& continueYesNo)
{
	cout<<"**************\4随机生成循双链表\4****************"<<endl<<endl;
	link.randCreate();

	cout<<"随机生成的循环双链表为："<<endl;
	cout<<link;
	cout<<endl;
	cout<<" **************************************************"<<endl<<endl;
	cout<<"  还继续吗(Y.继续\tN.结束)?";
	cin>>continueYesNo;
}
template <typename ElemType>
void ex3_4_12(MyDoubleLinkList<ElemType>& link,char& continueYesNo)
{
	cout<<"**************\4用已有的循环双链表初始化另一个循环双链表\4****************"<<endl<<endl;
	MyDoubleLinkList<ElemType> otherL(link);
	
	cout<<"初始化后的另一个非循环单链表为："<<endl;
	cout<<otherL;
	cout<<endl;
	cout<<" **************************************************"<<endl<<endl;
	cout<<"  还继续吗(Y.继续\tN.结束)?";
	cin>>continueYesNo;
}
template <typename ElemType>
void ex3_4_13(MyDoubleLinkList<ElemType>& link,char& continueYesNo)
{
		cout<<"*********************\4输入循环双链表\4*************************"<<endl<<endl;
	link.clear();
	cin>>link;
	cout<<"您输入的循环双链表为："<<endl;
	cout<<link;
	cout<<endl;
	cout<<" **************************************************"<<endl<<endl;
	cout<<"  还继续吗(Y.继续\tN.结束)?";
	cin>>continueYesNo;
}