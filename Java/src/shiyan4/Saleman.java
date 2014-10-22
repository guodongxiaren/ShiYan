package shiyan4;

public class Saleman extends Employee {
	double amount;//月销售额
	double factor;//酬金提取百分比
	/**
	 * 销售员的构造函数
	 * @param name   员工姓名
	 * @param id     职工号
	 * @param basic  基本工资
	 * @param amount 月销售额
	 * @param factor 酬金提取百分比
	 */
	public Saleman(String name,int id,double basic,double amount,double factor){
		super(name,id,basic);
		this.amount=amount;
		this.factor=factor;
	}
	@Override
	public void pay() {
		super.pay();
		this.performance=amount*factor;
		this.salary=basic+performance;
		sum+=salary;
	}
}
