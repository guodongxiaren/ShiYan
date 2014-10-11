#include <iostream>
using namespace std;
#include "ex4_1_Test.h"

void (*test[])(MySqStack<int>&,char& continueYesNo)={ex4_1_1,ex4_1_2,ex4_1_3,ex4_1_4,ex4_1_5,
														ex4_1_6,ex4_1_7,ex4_1_8,ex4_1_9};
void main()
{
	MySqStack<int> ss;
	int choose;
	char continueYesNo = 'N';
	ss.randomCreate();
	while(1)
	{
		choose = 0;
		system("cls");
		cout<<endl;
		cout<<"    **************测试顺序栈的操作****************"<<endl<<endl;
		cout<<"\t 1.在栈顶压入元素e"<<endl;
		cout<<"\t 2.弹出栈顶元素到e"<<endl;
		cout<<"\t 3.读栈顶的元素e"<<endl;
		cout<<"\t 4.判断顺序栈是否为空"<<endl;
		cout<<"\t 5.求顺序栈中元素的个数"<<endl;
		cout<<"\t 6.把一个顺序栈赋值给另一个顺序栈"<<endl;
		cout<<"\t 7.把顺序栈置空"<<endl;
		cout<<"       □8.随机生成顺序栈"<<endl;
		cout<<"       □9.用已有顺序栈初始化另一个新顺序栈"<<endl;
		cout<<"\t其他，结束"<<endl<<endl;
		cout<<"    ////////////////////////////////////////////////////"<<endl;
		displayCurrentObject(ss);
		cout<<"    ////////////////////////////////////////////////////"<<endl;
		cout<<"选择你要操作的代码（1-9）:";
		cin>>choose;
		if(choose>0&&choose<10)
		{
			system("cls");
			displayCurrentObject(ss);
		}
		else
			return;
		test[choose-1](ss,continueYesNo);
		if(continueYesNo=='N'||continueYesNo=='n')
			break;
	}
}