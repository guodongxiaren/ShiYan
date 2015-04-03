//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// myhead.h 包含自己设定的一些常量和类型

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef MYHEAD_H
#define MYHEAD_H
#endif
#include <cassert>
#include <new>
using namespace std;

#include <time.h>

const int	OK=1;
const int	ERROR=0;
const int	INFEASIBLE=-1;
//const int	OVERFLOW=-2;

typedef int Status;	//表示操作结果的状态

////////////////////////////////////////////////////////////////////////////////

//功能：判断两整数是否相等
//输入：函数的值参a和b为需要比较的两个整数
//输出：若a等于b，函数的返回值为OK;否则为ERROR
Status equal(int a,int b)
{
	if(a==b)
		return OK;
	else
		return ERROR;
}
				
//功能：判断一个整数是否大于另一个整数
//输入：函数的值参a和b为需要比较的两个整数
//输出：若a大于b，函数的返回值为OK；否则为ERROR
Status great(int a,int b)
{
	if(a>b)
		return OK;
	else
		return ERROR;
}	

//功能：判断一个整数是否小于另一个整数
//输入：函数的值参a和b为需要比较的两个整数
//输出：若a小于b，函数的返回值为OK；否则为ERROR
Status small(int a,int b)
{
	if(a<b)
		return OK;
	else
		return ERROR;
}
