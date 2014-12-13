#include <iostream>
using namespace std;
#ifndef MYLINKLIST_H
#define MYLINKLIST_H
#include "e:\wangwei\Test Include\MyLinkList.h"
#endif
#ifndef EX3_2_TEST_H
#define EX3_2_TEST_H
#include "ex3_2_Test.h"
#endif

void main()
{
	MyLinkList<int> link;
	link.randCreate();
	int choose;
	char continueYesNo = 'N';
	while(1)
	{
		choose = 0;
		system("cls");
		cout<<endl;

		cout<<"    **********测 试 非 循 环 单 链 表 的 操 作*********"<<endl<<endl;
		cout<<"\t 1.取非循环单链表的第i个结点"<<endl;
		cout<<"\t 2.在第i个结点之前插入一个数据域为e的结点"<<endl;
		cout<<"\t 3.判断非循环单链表是否为空"<<endl;
		cout<<"\t 4.求非循环单链表中结点的个数"<<endl;
		cout<<"\t 5.查找第1个与e满足compare()关系的结点"<<endl;
		cout<<"\t 6.返回某结点前驱的数据域"<<endl;
		cout<<"\t 7.返回某结点后继的数据域"<<endl;
		cout<<"\t 8.删除非循环单链表中数据域为e的第一个结点"<<endl;
		cout<<"\t 9.删除非循环单链表重复值"<<endl;
		cout<<"\t10.非循环单链表的逆置"<<endl;
		cout<<"\t11.把一个非循环单链表赋值给另一个非循环单链表"<<endl;
		cout<<"\t12.把一个非循环单链表置空"<<endl;
		cout<<"\t13.随机生成非循环单链表"<<endl;
		cout<<"\t14.用已有的非循环单链表初始化另一个非循环单链表"<<endl;
		cout<<"\t15.输入非循环单链表"<<endl;
		cout<<" \t其他，结束"<<endl<<endl;
		cout<<"    ////////////////////////////////////////////////////"<<endl;
		displayCurrentObject(link);
		cout<<"    ////////////////////////////////////////////////////"<<endl;
		cout<<"选择你要操作的代码（1-15）:";
		cin>>choose;
		if(choose>0&&choose<16)
		{
			system("cls");
			displayCurrentObject(link);
		}
		switch(choose)
		{
		case 1:ex3_2_1(link,continueYesNo);break;
		case 2:ex3_2_2(link,continueYesNo);break;
		case 3:ex3_2_3(link,continueYesNo);break;
		case 4:ex3_2_4(link,continueYesNo);break;
		case 5:ex3_2_5(link,continueYesNo);break;
		case 6:ex3_2_6(link,continueYesNo);break;
		case 7:ex3_2_7(link,continueYesNo);break;
		case 8:ex3_2_8(link,continueYesNo);break;
		case 9:ex3_2_9(link,continueYesNo);break;
		case 10:ex3_2_10(link,continueYesNo);break;
		case 11:ex3_2_11(link,continueYesNo);break;
		case 12:ex3_2_12(link,continueYesNo);break;
		case 13:ex3_2_13(link,continueYesNo);break;
		case 14:ex3_2_14(link,continueYesNo);break;
		case 15:ex3_2_15(link,continueYesNo);break;
		default:    cout<<"\n  你选择了结束"<<endl<<endl;
			return;
		}
		if(continueYesNo=='N'||continueYesNo=='n')
			break;
	}
}