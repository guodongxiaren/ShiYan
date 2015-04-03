#include <iostream>
using namespace std;
#ifndef MYSQLIST_H
#define MYSQLIST_H
#include "e:\wangwei\Test Include\MySqList.h"
#endif
#ifndef EX3_1_TEST_H
#define EX3_1_TEST_H
#include "e:\wangwei\ex3_1SqList\ex3_1_Test.h"
#endif
void main()
{
	MySqList<int> sq;
	int choose;
	char continueYesNo = 'N';
	sq.randCreate();
	while(1)
	{
		choose = 0;
		system("cls");
		cout<<endl;

		cout<<"    *********\4测 试 顺 序 表 的 操 作\4*********"<<endl<<endl;
		cout<<"\t 1.在第i个元素之前插入一个元素"<<endl;
		cout<<"\t 2.判断顺序表是否为空"<<endl;
		cout<<"\t 3.求顺序表中元素的个数"<<endl;
		cout<<"\t 4.取第i个元素"<<endl;
		cout<<"\t 5.查找第1个与某元素满足compare()关系的序号"<<endl;
		cout<<"\t 6.返回某元素的前驱"<<endl;
		cout<<"\t 7.返回某元素的后继"<<endl;
		cout<<"\t 8.删除第i个元素"<<endl;
		cout<<"\t 9.把一个顺序表赋值给另一个顺序表"<<endl;
		cout<<"\t10.把顺序表置空"<<endl;
		cout<<"\t11.随机生成顺序表（元素值为0到99之间的整数）"<<endl;
		cout<<"\t12.用已有的顺序表初始化另一个顺序表"<<endl;
		cout<<"\t13.输入顺序表"<<endl;
		cout<<"\t14.两个顺序表的并交差运算"<<endl;
		cout<<" \t其他，结束"<<endl<<endl;
		cout<<"////////////////////////////////////"<<endl;
		displayCurrentObject(sq);
		cout<<"////////////////////////////////////"<<endl;
		cout<<"    请选择你要操作的代码（1 -14）号码:";
		cin>>choose;
		if(choose>0&&choose<15)
		{
			system("cls");
			displayCurrentObject(sq);
		}
		switch(choose)
		{
		case 1:ex3_1_1(sq,continueYesNo);break;
		case 2:ex3_1_2(sq,continueYesNo);break;
		case 3:ex3_1_3(sq,continueYesNo);break;
		case 4:ex3_1_4(sq,continueYesNo);break;
		case 5:ex3_1_5(sq,continueYesNo);break;
		case 6:ex3_1_6(sq,continueYesNo);break;
		case 7:ex3_1_7(sq,continueYesNo);break;
		case 8:ex3_1_8(sq,continueYesNo);break;
		case 9:ex3_1_9(sq,continueYesNo);break;
		case 10:ex3_1_10(sq,continueYesNo);break;
		case 11:ex3_1_11(sq,continueYesNo);break;
		case 12:ex3_1_12(sq,continueYesNo);break;
		case 13:ex3_1_13(sq,continueYesNo);break;
		case 14:ex3_1_14(sq,continueYesNo);break;
		default:    cout<<"\n  你选择了结束"<<endl<<endl;
			return;
		}
		if(continueYesNo=='N'||continueYesNo=='n')
			break;
	}
}