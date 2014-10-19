package shiyan4;

import java.util.Scanner;

public class Employee {

	protected static double Level[]={2000,2500,3000,3500,4000};
	protected static double sum=0;
	protected String name; //姓名
	protected int id;      //工号
	protected int level;//工资级别
	protected double basic;//实发基本工资
	protected double performance;//业绩工资
	protected double salary;//月薪
	void pay(){
		System.out.println("请输入请假天数：");
		Scanner sc = new Scanner(System.in);
		int day=sc.nextInt();
		basic=level/30*(30-day);
		this.salary=basic+performance;
		//sc.close();
	}

	public static double sumSalary(){
		return sum;
	}
	public static void main(String[] args) {
		Technician a=new Technician("张三", 1, 1, 1500);
		Manager b = new Manager("李四", 2, 2,1000, 0.8);
		Saleman c = new Saleman("王五",3,0,0.7);
		a.pay();
		b.pay();
		c.pay();
		System.out.println(sumSalary());
	}
}
