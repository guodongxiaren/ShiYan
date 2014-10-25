package shiyan4;

public class Manager extends Employee {
	double prize;
	double factor;
	/**
	 * 经理的构造函数
	 * @param name  姓名
	 * @param id    职工号
	 * @param basic 基本工资
	 * @param pr    固定奖金
	 * @param fac   业绩系数
	 */
	public Manager(String name,int id,double basic,double pr,double fac){
		super(name,id,basic);
		this.prize=pr;
		this.factor=fac;
	}
	@Override
	public void pay() {
		super.pay();
		this.performance=prize*factor;
		this.salary=basic+performance;
		sum+=salary;
	}
}
