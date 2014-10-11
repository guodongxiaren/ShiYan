/////////////////////////////////////////////////
//ExampleClass.h长方形数据结构C++类定义（基类）
/////////////////////////////////////////////////
template <typename ElemType>
class Rectangle
{
public:
	//长方形的序号类
	class RectangleNo
	{
	public:
		int no;
	};
	void setNo(int i);
	void setLength(ElemType a);
	void setWidth(ElemType a);
	ElemType area();
	//
	Rectangle();
	Rectangle(const Rectangle& otherD);
	virtual ~Rectangle();
protected:
	ElemType length;
	ElemType width;
	RectangleNo myNo;
};
/////////////////////////////////////////////////
//长方形数据结构C++实现（基类）
/////////////////////////////////////////////////
template <typename ElemType>
Rectangle<ElemType>::Rectangle()
{
	length = width = 0;
	cout<<"    自动调用构造函数"<<endl;
}
//拷贝构造函数
template <typename ElemType>
Rectangle<ElemType>::Rectangle(const Rectangle<ElemType>& otherD)
{
	length = otherD.length;
	width = otherD.width;
	myNo = otherD.myNo;
	cout<<"    自动调用拷贝初始化构造函数为(";
	cout<<length<<","<<width<<")"<<endl;
}
//析构函数
template <typename ElemType>
Rectangle<ElemType>::~Rectangle()
{
	cout<<"\n    第"<<myNo.no<<"个长方形对象("<<length<<","<<width<<")生存期结束"<<endl;
}
//功能:设置长方形的序号
template <typename ElemType>
void Rectangle<ElemType>::setNo(int i)
{
	myNo.no=i;
}
//功能：设置长方形长度
template <typename ElemType>
void Rectangle<ElemType>::setLength(ElemType a)
{
	length = a;
}
//功能：设置长方形宽度
template <typename ElemType>
void Rectangle<ElemType>::setWidth(ElemType a)
{
	width = a;
}
//功能：求长方形面积
template <typename ElemType>
ElemType Rectangle<ElemType>::area()
{
	return length*width;
}