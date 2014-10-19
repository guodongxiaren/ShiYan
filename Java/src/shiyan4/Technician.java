package shiyan4;

public class Technician extends Employee {
	double hours;
	double moneyPerHour;
	double factor;
	public Technician(String name,int id,int le,double mph){
		this.name=name;
		this.id=id;
		this.level=le;
		this.moneyPerHour=mph;
	}
	@Override
	void pay() {
		super.pay();
		this.performance=moneyPerHour*hours*factor;
		this.salary=basic+performance;
		sum+=salary;
	}
	
}
