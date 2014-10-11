//#include "E:\wangwei\Test Include\MyExampleClass.h"
//显示长方形
template <typename ElemType>
void displayCurrentObject(MyRectangle<ElemType> rec)
{
	cout<<endl;
	cout<<rec;
}
//测试ex2_1_1:设置长方形的序号
template <typename ElemType>
void ex2_1_1(MyRectangle<ElemType>& rec,char& continueYesNo)
{
	int no;
	cout<<" ************设置长方形的序号************"<<endl<<endl;
	cout<<"    请输入当前长方形对象的序号: ";
	cin>>no;
	rec.setNo(no);
	cout<<rec;

	cout<<" ***************************************"<<endl<<endl;
	cout<<"  还继续吗(Y.继续\tN.结束)?";
	cin>>continueYesNo;
}
//测试：设置长方形的长
template <typename ElemType>
void ex2_1_2(MyRectangle<ElemType>& rec,char& continueYesNo)
{
	float aL;
	cout<<" **************设置长方形的长**************"<<endl<<endl;
	cout<<" 请输入当前长方形对象的长:";
	cin>>aL;
	rec.setLength(aL);
	cout<<rec;

	cout<<" *****************************************"<<endl<<endl;
	cout<<" 还继续吗(Y.继续\tN.结束)?";
	cin>>continueYesNo;
}
//长方形对象的赋值
template <typename ElemType>
void ex2_1_3(MyRectangle<ElemType>rec,char& continueYesNo)
{
	MyRectangle<float> recOther;
	cout<<" ************长方形对象的赋值****************"<<endl<<endl;
	cout<<"    把当前长方形对象赋值给另一个长方形对象"<<endl;
	recOther = rec;
	cout<<"\n    赋值后，另一个长方形对象为: "<<endl;
	cout<<recOther;
	cout<<" *****************************************"<<endl<<endl;
	cout<<" 还继续吗(Y.继续\tN.结束)?";
	cin>>continueYesNo;
}
//测试：设置长方形的宽
template <typename ElemType>
void ex2_1_4(MyRectangle<ElemType>& rec,char& continueYesNo)
{
	float aL;
	cout<<" **************设置长方形的宽**************"<<endl<<endl;
	cout<<" 请输入当前长方形对象的宽:";
	cin>>aL;
	rec.setWidth(aL);
	cout<<rec;

	cout<<" *****************************************"<<endl<<endl;
	cout<<" 还继续吗(Y.继续\tN.结束)?";
	cin>>continueYesNo;
}
//测试：求长方形的面积
template <typename ElemType>
void ex2_1_5(MyRectangle<ElemType>& rec,char& continueYesNo)
{
	cout<<" **************长方形的面积**************"<<endl<<endl;
	cout<<rec.area()<<endl;

	cout<<" *****************************************"<<endl<<endl;
	cout<<" 还继续吗(Y.继续\tN.结束)?";
	cin>>continueYesNo;
}
