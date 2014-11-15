package shiyan3;

import java.util.Scanner;

public class Stack {
	int stacksize=10;
	private int[] elem;
	public Stack(int stacksize) {
		elem = new int[stacksize];
		this.stacksize = stacksize;
	}
	//当前栈中元素的个数
	private int count;
	public boolean isEmpty(){
		return count==0?true:false;
	}
	public boolean isFull(){
		return count==stacksize?true:false;
	}
	public void push(int var){
		if(this.isFull()){
			System.out.println("栈已满，不能进栈!!!");
			return;
		}
		elem[count++]=var;
	}
	public void  pop(){
		if(this.isEmpty()){
			System.out.println("栈已空，不能进栈!!!");
			return ;
		}
		--count;
		return;
	}
	public void print(){
		System.out.println("当前栈中的元素为：");
		for(int i=0;i<count;i++)
			System.out.print(elem[i]+" ");
		System.out.println();
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println("请输入栈的大小");
		@SuppressWarnings("resource")
		Scanner sc = new Scanner(System.in);
		int size = sc.nextInt();
		Stack s = new Stack(size);
		int op;
		while(true){
			System.out.println("请选择要进行的操作：1 进栈；2 出栈 ");
			op=sc.nextInt();
			if(op==1){
				System.out.print("请输入要进栈的数:");
				int var=sc.nextInt();
				s.push(var);
				s.print();
			}
			else if(op==2){
				s.pop();
				s.print();
			}
			else{
				System.out.println("输入有误，请重新输入。");
			}
		}
	}

}
