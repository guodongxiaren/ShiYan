package shiyan4;

/*
 * 某公司雇员（Employee）包括经理（Manager）、技术人员（Technician）和销售员（Saleman）。
 * 以Employee类为基类，派生出manager、technician和saleman类。
 * Employee类的属性包括姓名、职工号、工资级别、月薪（实发基本工资加业绩工资）；
 操作包括月薪计算函数pay()，该函数要求输入请假天数，扣除应扣工资后，得出实发基本工资。
 * Technician类派生的属性有每小时附加酬金和当月工作时数，以及研究完成进度系数，业绩工资为三者之积。
 也包括同名的pay函数，工资总额为基本工资加业绩工资。
 * Saleman类派生的属性有当月销售额和酬金提取百分比，业绩工资为两者之积。也包括同名的pay函数，工资总额为基本工资加业绩工资。
 * Manager类派生的属性有固定奖金额和业绩系数，业绩工资为两者之积。工资总额也为基本工资加业绩工资。
 * 另外设计一个函数计算所有员工工资总和。
 */
import java.util.Scanner;

public class Employee {

	protected static double sum = 0;//公司所有员工工资之和
	protected String name; // 姓名
	protected int id; // 工号
	protected double basic;// 实发基本工资
	protected double performance;// 业绩工资
	protected double salary;// 月薪

	/**
	 * @param name
	 * @param id
	 * @param basic
	 */
	public Employee(String name, int id, double basic) {
		this.name = name;
		this.id = id;
		this.basic = basic;
	}

	public void pay() {
		System.out.println("请输入请假天数：");
		@SuppressWarnings("resource")
		Scanner sc = new Scanner(System.in);
		int day = sc.nextInt();
		basic = basic / 30 * (30 - day);
		this.salary = basic + performance;
		// sc.close();//这里关闭sc会有问题
	}

	public static double sumSalary() {
		return sum;
	}

	public static void main(String[] args) {
		Technician a = new Technician("张三", 1, 5000, 200, 50, 0.8);
		Manager b = new Manager("李四", 2, 4000, 1000, 0.8);
		Saleman c = new Saleman("王五", 3, 2000, 100, 0.7);
		a.pay();
		b.pay();
		c.pay();
		System.out.println("所有员工工资总和"+sumSalary());
	}
}
