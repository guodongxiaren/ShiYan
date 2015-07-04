#include <iostream>
#include "HuffmanCodec.h"
using namespace std;

void menu()
{
	cout<<endl;
	cout<<"============================================="<<endl;
	cout<<"       请选择要进行的操作"<<endl;
	cout<<"                 C: 编码"<<endl;
	cout<<"                 D: 解码"<<endl;
	cout<<"                 P: 打印代码文件"<<endl;
	cout<<"                 T: 打印哈夫曼树"<<endl;
	cout<<"              其他: 退出程序"<<endl;
	cout<<"============================================="<<endl;
	cout<<endl;
}
int main()
{
	bool flag = true;
	HuffmanCodec hf;
	char input;
	while(flag)
	{
		menu();
		cin>>input;
		switch (input)
		{
		case 'C':
		case 'c':
			hf.coding();
			break;
		case 'D':
		case 'd':
			hf.decoding();
			break;
		case 'P':
		case 'p':
			hf.print();
			break;
		case 'T':
		case 't':
			hf.treePrint();
			break;
		default:
			flag = false;
		}
	}
}