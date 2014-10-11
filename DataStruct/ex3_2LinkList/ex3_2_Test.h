//显示长方形
template <typename ElemType>
void displayCurrentObject(MyLinkList<ElemType>& link)
{
	int len = link.getLength();
	cout<<"当前非循环单链表有"<<len<<"个元素,分别为："<<endl;
	cout<<endl;
	if(len)
	cout<<link;
}

//
template <typename ElemType>
void ex3_2_1(MyLinkList<ElemType>& link,char& continueYesNo)
{
	int i;
	ElemType e;
	cout<<"************取非循环单链表的第i个结点************"<<endl<<endl;
	cout<<"请输入你要取的结点的序号：";
	cin>>i;
	if(link.getElem(i,e)==ERROR)
		cout<<"错误!该链表中没有第"<<i<<"的结点"<<endl;
	else
	    cout<<"你要取非循环单链表的第4个结点的数据域为"<<e<<endl<<endl;

	cout<<" ***************************************"<<endl<<endl;
	cout<<"  还继续吗(Y.继续\tN.结束)?";
	cin>>continueYesNo;
}
template <typename ElemType>
void ex3_2_2(MyLinkList<ElemType>& link,char& continueYesNo)
{
	int i;
	ElemType e;
	cout<<"**********在第i个结点之前插入一个数据域为e的结点*********"<<endl<<endl;
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
void ex3_2_3(MyLinkList<ElemType>& link,char& continueYesNo)
{
	cout<<"************判断非循环单链表是否为空************"<<endl<<endl;
	printf("当前非循环单链表%s\n",link.isEmpty()?"为空":"不为空");
	cout<<" ***************************************"<<endl<<endl;
	cout<<"  还继续吗(Y.继续\tN.结束)?";
	cin>>continueYesNo;
}
template <typename ElemType>
void ex3_2_4(MyLinkList<ElemType>& link,char& continueYesNo)
{
	cout<<"************求非循环单链表中结点的个数************"<<endl<<endl;
	cout<<"非循环单链表中结点的个数为："<<link.getLength()<<endl;
	cout<<" ***************************************"<<endl<<endl;
	cout<<"  还继续吗(Y.继续\tN.结束)?";
	cin>>continueYesNo;
}
template <typename ElemType>
void ex3_2_5(MyLinkList<ElemType>& link,char& continueYesNo)
{
	ElemType e;
	int i;
	cout<<"***********查找第1个与e满足compare()关系的结点***********"<<endl;
	cout<<"查找等于某个结点的操作"<<endl;
	cout<<"请输入你想查找的结点：";
	cin>>e;
	if(link.locateElem(e,equal,i)==ERROR)
		cout<<"\t该链表中没有和"<<e<<"相等的结点"<<endl<<endl;
	else
		cout<<"\t数据域等于"<<e<<"的第一个结点的序号为"<<i<<endl<<endl;

	cout<<"查找大于某个结点的操作"<<endl;
	cout<<"请输入你想查找的结点：";
	cin>>e;
	if(link.locateElem(e,great,i)==ERROR)
		cout<<"\t该链表中没有大于"<<e<<"的结点"<<endl<<endl;
	else
		cout<<"\t数据域大于"<<e<<"的第一个结点的序号为"<<i<<endl<<endl;

	cout<<"查找小于某个结点的操作"<<endl;
	cout<<"请输入你想查找的结点：";
	cin>>e;
	if(link.locateElem(e,less1,i)==ERROR)
		cout<<"\t该链表中小于"<<e<<"的结点"<<endl<<endl;
	else
		cout<<"\t数据域小于"<<e<<"的第一个结点的序号为"<<i<<endl<<endl;

	cout<<" ***************************************"<<endl<<endl;
	cout<<"  还继续吗(Y.继续\tN.结束)?";
	cin>>continueYesNo;
}
template <typename ElemType>
void ex3_2_6(MyLinkList<ElemType>& link,char& continueYesNo)
{
	ElemType e,prior_e;
	cout<<"************返回某结点前驱的数据域************"<<endl<<endl;
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
void ex3_2_7(MyLinkList<ElemType>& link,char& continueYesNo)
{
	ElemType e,next_e;
	cout<<"************返回某结点后继的数据域************"<<endl<<endl;
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
void ex3_2_8(MyLinkList<ElemType>& link,char& continueYesNo)
{
	ElemType e;
	cout<<"*********删除非循环单链表中数据域为e的第一个结点********"<<endl;
	cout<<"请输入你想删除结点的数据域：";
	cin>>e;
	if(link.deleteElem(e)==ERROR)
		cout<<"错误!该链表中无此结点"<<endl;
	else
	{
		cout<<endl<<"删除后非循环单链表为"<<endl;
		cout<<link;
	}
	cout<<" ***************************************"<<endl<<endl;
	cout<<"  还继续吗(Y.继续\tN.结束)?";
	cin>>continueYesNo;
}
template <typename ElemType>
void ex3_2_9(MyLinkList<ElemType>& link,char& continueYesNo)
{

	cout<<"************删除非循环单链表中的重复值************"<<endl;
	link.deleteRepeat();
	cout<<endl<<link;

	cout<<" ***************************************"<<endl<<endl;
	cout<<"  还继续吗(Y.继续\tN.结束)?";
	cin>>continueYesNo;
}
//非循环单链表的逆置
template <typename ElemType>
void ex3_2_10(MyLinkList<ElemType>& link,char& continueYesNo)
{

	cout<<"************非循环单链表的逆置************"<<endl<<endl;
	cout<<"非循环单链表逆置后为："<<endl;
	link.adverse();
	cout<<link;

	cout<<" ***************************************"<<endl<<endl;
	cout<<"  还继续吗(Y.继续\tN.结束)?";
	cin>>continueYesNo;
}
//把一个非循环单链表赋值给另一个非循环单链表
template <typename ElemType>
void ex3_2_11(MyLinkList<ElemType>& link,char& continueYesNo)
{

	cout<<"*******把另一个非循环单链表赋值个当前非循环单链表*******"<<endl;
	MyLinkList<int> otherL;
	otherL.randCreate();
	link = otherL;
	cout<<endl<<"另一个非循环单链表赋值给当前非循环单链表为："<<endl<<link;
	cout<<" ***************************************"<<endl<<endl;
	cout<<"  还继续吗(Y.继续\tN.结束)?";
	cin>>continueYesNo;
}
//把非循环单链表置空
template <typename ElemType>
void ex3_2_12(MyLinkList<ElemType>& link,char& continueYesNo)
{

	cout<<"*************把当前非循环单链表置空*****************"<<endl;
	link.clear();
	cout<<endl<<"当前非循环单链表置空后，结点个数为："<<link.getLength()<<endl<<endl;
	cout<<" ***************************************"<<endl<<endl;
	cout<<"  还继续吗(Y.继续\tN.结束)?";
	cin>>continueYesNo;
}
//随机生成非循环单链表
template <typename ElemType>
void ex3_2_13(MyLinkList<ElemType>& link,char& continueYesNo)
{
	cout<<"**************随机生成非循环单链表****************"<<endl<<endl;
	link.randCreate();

	cout<<"随机生成的非循环单链表为："<<endl;
	cout<<link;
	cout<<endl;
	cout<<" **************************************************"<<endl<<endl;
	cout<<"  还继续吗(Y.继续\tN.结束)?";
	cin>>continueYesNo;
}
//用已有的非循环单链表初始化非循环单链表
template <typename ElemType>
void ex3_2_14(MyLinkList<ElemType>& link,char& continueYesNo)
{
	cout<<"**************用已有的非循环单链表初始化非循环单链表****************"<<endl<<endl;
	MyLinkList<ElemType> otherL(link);
	
	cout<<"初始化后的另一个非循环单链表为："<<endl;
	cout<<otherL;
	cout<<endl;
	cout<<" **************************************************"<<endl<<endl;
	cout<<"  还继续吗(Y.继续\tN.结束)?";
	cin>>continueYesNo;
}
//输入非循环单链表
template <typename ElemType>
void ex3_2_15(MyLinkList<ElemType>& link,char& continueYesNo)
{
	cout<<"*********************输入非循环单链表*************************"<<endl<<endl;
	link.clear();
	cin>>link;
	cout<<"您输入的非循环单链表为："<<endl;
	cout<<link;
	cout<<endl;
	cout<<" **************************************************"<<endl<<endl;
	cout<<"  还继续吗(Y.继续\tN.结束)?";
	cin>>continueYesNo;
}

