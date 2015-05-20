#include <iostream>
using namespace std;
#include "ex5_1_Test.h"
void (*test[])(MySqQueue<int>&,char& continueYesNo)={ex5_1_1,ex5_1_2,ex5_1_3,ex5_1_4,ex5_1_5,
														ex5_1_6,ex5_1_7,ex5_1_8,ex5_1_9,ex5_1_10};
void main()
{
	MySqQueue<int> ss;
	int choose;
	char continueYesNo = 'N';
	ss.randomCreate();
	while(1)
	{
		choose = 0;
		system("cls");
		cout<<endl;
		cout<<"    **************测试循环顺序队列的操作****************"<<endl<<endl;
		cout<<"\t 1.进队列(在循环顺序队列队尾插入元素)"<<endl;
		cout<<"\t 2.出队列(删除循环顺序队列对头元素)"<<endl;
		cout<<"\t 3.读循环顺序队列队头的元素到e"<<endl;
		cout<<"\t 4.判断循环顺序队列是否为空"<<endl;
		cout<<"\t 5.判断循环顺序队列是否满"<<endl;
		cout<<"\t 6.求循环顺序队列中元素的个数"<<endl;
		cout<<"\t 7.把一个循环顺序队列赋值给另一个循环顺序队列"<<endl;
		cout<<"      □ 8.把循环顺序队列置空"<<endl;
		cout<<"      □ 9.随机生成循环顺序队列"<<endl;
		cout<<"      □10.用已有循环顺序队列初始化另一个新循环顺序队列"<<endl;
		cout<<"\t其他，结束"<<endl<<endl;
		cout<<"    ////////////////////////////////////////////////////"<<endl;
		displayCurrentObject(ss);
		cout<<"    ////////////////////////////////////////////////////"<<endl;
		cout<<"选择你要操作的代码（1-10）:";
		cin>>choose;
		if(choose>0&&choose<11)
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