package shiyan4;

public class Manager extends Employee {
	double prize;
	double factor;
	public Manager(String name,int id,int le,double pr,double fac){
		this.name=name;
		this.id=id;
		this.level=le;
		this.prize=pr;
		this.factor=fac;
	}
	@Override
	void pay() {
		super.pay();
		this.performance=prize*factor;
		this.salary=basic+performance;
		sum+=salary;
	}

}
