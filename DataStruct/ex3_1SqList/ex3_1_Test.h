//#include "E:\wangwei\Test Include\MySqList.h"
//显示长方形
template <typename ElemType>
void displayCurrentObject(MySqList<ElemType> sq)
{
	cout<<"当前顺序表有"<<sq.getLength()<<"个元素,分别为："<<endl;
	cout<<sq;
}

//测试ex3_1_1:在第i个元素之前插入一个元素
template <typename ElemType>
void ex3_1_1(MySqList<ElemType>& sq,char& continueYesNo)
{
	int i;
	ElemType e;
	cout<<" ***********\4在第i个元素之前插入一个元素\4**********"<<endl<<endl;
	cout<<"    请输入你要在第几个元素之前插入元素: ";
	cin>>i;
	cout<<"    请输入你要插入的元素的值: ";
	cin>>e;
	cout<<"    你要在第"<<i<<"个元素之前插入元素"<<e<<endl;
	if(sq.insert(i,e)==ERROR)
		cout<<"    错误！无此位置"<<endl;
	else
		cout<<sq;
	
	cout<<" ***************************************"<<endl<<endl;
	cout<<"  还继续吗(Y.继续\tN.结束)?";
	cin>>continueYesNo;
}
//ex3_1_Test.h单独的一个头文件
//测试：判断顺序表是否为空
template <typename ElemType>
void ex3_1_2(MySqList<ElemType>& sq,char& continueYesNo)
{
	cout<<" ***********\4判断顺序表是否为空\4**********"<<endl<<endl;
	if(sq.isEmpty())
		cout<<"当前顺序表为空"<<endl;
	else
	{
		cout<<"当前顺序表不为空"<<endl;
		cout<<sq;
	}
	cout<<" *****************************************"<<endl<<endl;
	cout<<" 还继续吗(Y.继续\tN.结束)?";
	cin>>continueYesNo;
}
//测试：求顺序表中元素的个数
template <typename ElemType>
void ex3_1_3(MySqList<ElemType>& sq,char& continueYesNo)
{
	cout<<" *************\4求顺序表中元素的个数\4************"<<endl<<endl;
	cout<<"顺序表元素个数为："<<sq.getLength()<<endl;
	cout<<" *****************************************"<<endl<<endl;
	cout<<" 还继续吗(Y.继续\tN.结束)?";
	cin>>continueYesNo;
}
//测试：取第i个元素
template <typename ElemType>
void ex3_1_4(MySqList<ElemType>& sq,char& continueYesNo)
{
	int i;
	ElemType e;
	cout<<" ************\4 取 第 i 个 元 素 \4**************"<<endl<<endl;
	cout<<"    请输入你想取的元素序号（1--10）:";
	cin>>i;
	if(sq.getElem(i,e)==ERROR)
		cout<<"    错误！无此元素"<<endl;
	else
		cout<<"    你想取的第"<<i<<"个元素的值为："<<e<<endl;
	cout<<" *****************************************"<<endl<<endl;
	cout<<" 还继续吗(Y.继续\tN.结束)?";
	cin>>continueYesNo;
}
//测试：查找第1个与某元素满足compare()关系的序号
template <typename ElemType>
void ex3_1_5(MySqList<ElemType>& sq,char& continueYesNo)
{
	ElemType e;
	cout<<" *******\4查找第1个与某元素满足compare()关系的序号\4********"<<endl<<endl;
	cout<<"\t查找等于某个元素的操作"<<endl;
	cout<<"\t请输入你想查找的元素：";
	cin>>e;
	cout<<"你想查找的第一个等于"<<e<<"的元素的序号为"<<sq.locateElem(e,equal)<<endl<<endl;
	
	cout<<"\t查找大于某个元素的操作"<<endl;
	cout<<"\t请输入你想查找的元素：";
	cin>>e;
	cout<<"你想查找的第一个大于"<<e<<"的元素的序号为"<<sq.locateElem(e,great)<<endl<<endl;
	
	cout<<"\t查找小于某个元素的操作"<<endl;
	cout<<"\t请输入你想查找的元素：";
	cin>>e;
	cout<<"你想查找的第一个小于"<<e<<"的元素的序号为"<<sq.locateElem(e,less1)<<endl<<endl;
	cout<<" *****************************************"<<endl<<endl;
	cout<<" 还继续吗(Y.继续\tN.结束)?";
	cin>>continueYesNo;
}
//测试：返回某元素的前驱
template <typename ElemType>
void ex3_1_6(MySqList<ElemType>& sq,char& continueYesNo)
{
	ElemType e,e1;
	cout<<" ***********\4返回某元素的前驱\4***********"<<endl<<endl;
	cout<<"    请输入你想查找其前驱的元素：";
	cin>>e;
	if(sq.priorElem(e,e1)==ERROR)
		cout<<"    错误！没有这个元素或者该元素是第一个元素没有前驱"<<endl;
	else
		cout<<"    你想查找的元素"<<e<<"的前驱为"<<e1<<endl;
	
	cout<<" *****************************************"<<endl<<endl;
	cout<<" 还继续吗(Y.继续\tN.结束)?";
	cin>>continueYesNo;
}
//测试：返回某元素的后继
template <typename ElemType>
void ex3_1_7(MySqList<ElemType>& sq,char& continueYesNo)
{
	ElemType e,e1;
	cout<<" **********\4返回某元素的后继\4**********"<<endl<<endl;
		cout<<"    请输入你想查找其后继的元素：";
	cin>>e;
	if(sq.nextElem(e,e1)==ERROR)
		cout<<"    错误！没有这个元素或者该元素是最后一个元素没有后继"<<endl;
	else
		cout<<"    你想查找的元素"<<e<<"的后继为"<<e1<<endl;
	
	cout<<" *****************************************"<<endl<<endl;
	cout<<" 还继续吗(Y.继续\tN.结束)?";
	cin>>continueYesNo;
}
//测试：删除第i个元素
template <typename ElemType>
void ex3_1_8(MySqList<ElemType>& sq,char& continueYesNo)
{
	int i;
	ElemType e;
	cout<<" *******\4删除第i个元素\4********"<<endl<<endl;
	cout<<"    请输入你想删除元素的序号(1--10):";
	cin>>i;
	if(sq.deleteElem(i,e)==ERROR)
		cout<<"    错误！没有这个元素"<<endl;
	else
		cout<<"    你想删除的第"<<i<<"个元素的值为"<<e<<endl;
	cout<<"    删除后的顺序表为"<<endl;
	cout<<sq;
	cout<<" *****************************************"<<endl<<endl;
	cout<<" 还继续吗(Y.继续\tN.结束)?";
	cin>>continueYesNo;
}
//测试：把一个顺序表赋值给另一个顺序表
template <typename ElemType>
void ex3_1_9(MySqList<ElemType>& sq,char& continueYesNo)
{
	MySqList<ElemType> other;
	cout<<" *******\4把一个顺序表赋值给另一个顺序表\4********"<<endl<<endl;
	other = sq;
	cout<<"    另一个顺序表赋值给当前顺序表为："<<endl;
	cout<<other;
	
	cout<<" *****************************************"<<endl<<endl;
	cout<<" 还继续吗(Y.继续\tN.结束)?";
	cin>>continueYesNo;
}
//测试：把顺序表置空
template <typename ElemType>
void ex3_1_10(MySqList<ElemType>& sq,char& continueYesNo)
{
	cout<<" *******\4把顺序表置空\4********"<<endl<<endl;
	sq.clear();
	cout<<"    当前顺序表置空后，元素的个数为："<<sq.getLength()<<endl;
	
	cout<<" *****************************************"<<endl<<endl;
	cout<<" 还继续吗(Y.继续\tN.结束)?";
	cin>>continueYesNo;
}
//随机生成顺序表（元素值为0到99之间的整数）
template <typename ElemType>
void ex3_1_11(MySqList<ElemType>& sq,char& continueYesNo)
{
	cout<<" *******\4随机生成顺序表（元素值为0到99之间的整数）\4********"<<endl<<endl;
	sq.randCreate();
	cout<<"当前顺序表为："<<endl;
	cout<<sq;
	
	cout<<" *****************************************"<<endl<<endl;
	cout<<" 还继续吗(Y.继续\tN.结束)?";
	cin>>continueYesNo;
}
//用已有的顺序表初始化另一个顺序表
template <typename ElemType>
void ex3_1_12(MySqList<ElemType>& sq,char& continueYesNo)
{
	cout<<" *************\4用已有的顺序表初始化另一个顺序表\4************"<<endl<<endl;
	MySqList<ElemType> sqOther(sq);
	cout<<"\n    初始化后的另一个顺序表对象为: "<<endl;
	cout<<sqOther;
	cout<<" *****************************************"<<endl<<endl;
	cout<<" 还继续吗(Y.继续\tN.结束)?";
	cin>>continueYesNo;
}
//输入顺序表
template <typename ElemType>
void ex3_1_13(MySqList<ElemType>& sq,char& continueYesNo)
{
	cout<<" *************\4输入顺序表\4************"<<endl<<endl;
	cin>>sq;
	cout<<sq;
	cout<<" *****************************************"<<endl<<endl;
	cout<<" 还继续吗(Y.继续\tN.结束)?";
	cin>>continueYesNo;
}
//两个顺序表的并交差运算
template <typename ElemType>
void ex3_1_14(MySqList<ElemType>& sq,char& continueYesNo)
{
	system("cls");
	cout<<" *************\4两个顺序表的并交差运算\4************"<<endl<<endl;
	MySqList<int> sq2;
	sq2.randCreate();
	cout<<"第一个顺序表为："<<endl;
	cout<<sq;
	cout<<"第二个顺序表为："<<endl;
	cout<<sq2;
	cout<<"以上两个顺序表的"<<endl;
	cout<<"并集为:"<<endl;
	cout<<unionSet(sq,sq2);
	cout<<"交集为:"<<endl;
	cout<<intersectionSet(sq,sq2);
	cout<<"差集为:"<<endl;
	cout<<dirfferenceSet(sq,sq2);
	cout<<" *****************************************"<<endl<<endl;
	cout<<" 还继续吗(Y.继续\tN.结束)?";
	cin>>continueYesNo;
}


