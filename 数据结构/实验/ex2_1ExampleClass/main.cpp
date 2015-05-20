#include <iostream>
using namespace std;
#ifndef MYEXAMPLECLASS_H
#define MYEXAMPLECLASS_H
#include "E:\wangwei\Test Include\MyExampleClass.h"
#endif
#ifndef EX2_1_TEST_H
#define EX2_1_TEST_H
#include "E:\wangwei\ex2_1ExampleClass\ex2_1_Test.h"
#endif
void main()
{
	MyRectangle<float> rec;
	int choose;
	char continueYesNo = 'N';
	while(1)
	{
		choose = 0;
		system("cls");
		cout<<endl;
		
		cout<<"    *********测试长方形的操作*********"<<endl<<endl;
		cout<<"\t 1.设置长方形的序号"<<endl;
		cout<<"\t 2.设置长方形的长"<<endl;
		cout<<"\t 3.重载赋值运算符的定义"<<endl;
		cout<<"\t 4.设置长方形的宽"<<endl;
		cout<<"\t 5.求长方形面积"<<endl;
		cout<<"    其他，结束"<<endl<<endl;
		cout<<"////////////////////////////////////"<<endl;
		displayCurrentObject(rec);
		cout<<"////////////////////////////////////"<<endl;
		cout<<"    请选择你要操作的代码（1 -5）号码:";
		cin>>choose;
		if(choose>0&&choose<6)
		{
			system("cls");
			displayCurrentObject(rec);
		}
		switch(choose)
		{
		case 1:ex2_1_1(rec,continueYesNo);break;
		case 2:ex2_1_2(rec,continueYesNo);break;
		case 3:ex2_1_3(rec,continueYesNo);break;
		case 4:ex2_1_4(rec,continueYesNo);break;
		case 5:ex2_1_5(rec,continueYesNo);break;
		default:    cout<<"\n  你选择了结束"<<endl<<endl;
			return;
		}
		if(continueYesNo=='N'||continueYesNo=='n')
			break;
	}
}