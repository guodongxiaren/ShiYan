#include<iostream>
using namespace std;
#ifndef EX_3_4_TEST_H
#define EX_3_4_TEST_H
#include "ex_3_4_Test.h"
#endif
void (*test[])(MyDoubleLinkList<int>&,char& continueYesNo)={ex3_4_1,ex3_4_2,ex3_4_3,ex3_4_4,ex3_4_5,
															ex3_4_6,ex3_4_7,ex3_4_8,ex3_4_9,ex3_4_10,
															ex3_4_11,ex3_4_12,ex3_4_13};
void main()
{
	MyDoubleLinkList<int> link;
	link.randCreate();
	int choose;
	char continueYesNo = 'N';
	while(1)
	{
		choose = 0;
		system("cls");
		cout<<endl;

		cout<<"    *************测 试 循 环 双 链 表 的 操 作************"<<endl<<endl;
		cout<<"\t 1.取循环单链表的第i个结点数据域"<<endl;
		cout<<"\t 2.在第i个结点之前插入一个数据域为e的结点"<<endl;
		cout<<"\t 3.判断循环单链表是否为空"<<endl;
		cout<<"\t 4.求循环单链表中结点的个数"<<endl;
		cout<<"\t 5.返回循环双链表中数据域为e的第一个结点的指针"<<endl;
		cout<<"\t 6.返回某结点前驱的数据域"<<endl;
		cout<<"\t 7.返回某结点后继的数据域"<<endl;
		cout<<"\t 8.删除循环单链表中数据域为e的第一个结点"<<endl;
		cout<<"\t 9.把一个循环单链表赋值给另一个非循环单链表"<<endl;
		cout<<"\t10.把循环单链表的置空"<<endl;
		cout<<"      □11.随机生成非循环单链表"<<endl;
		cout<<"      □12.用已有的非循环单链表初始化另一个非循环单链表"<<endl;
		cout<<"      □13.输入非循环单链表"<<endl;
		cout<<" \t其他，结束"<<endl<<endl;
		cout<<"    ////////////////////////////////////////////////////"<<endl;
		displayCurrentObject(link);
		cout<<"    ////////////////////////////////////////////////////"<<endl;
		cout<<"选择你要操作的代码（1-13）:";
		cin>>choose;
		if(choose>0&&choose<14)
		{
			system("cls");
			displayCurrentObject(link);
			test[choose-1](link,continueYesNo);
		}
		else
			return;
		
		if(continueYesNo=='N'||continueYesNo=='n')
			break;
	}
}
