package shiyan4;

public class Saleman extends Employee {
	double amount;//月销售额
	double factor;//酬金提取百分比
	public Saleman(String name,int id,int le,double amount){
		this.name=name;
		this.id=id;
		this.level=le;
		this.amount=amount;
	}
	@Override
	void pay() {
		super.pay();
		this.performance=amount*factor;
		this.salary=basic+performance;
		sum+=salary;
	}
	
}
