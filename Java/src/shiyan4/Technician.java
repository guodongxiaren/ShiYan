package shiyan4;
 
public class Technician extends Employee {
	double hours;
	double moneyPerHour;
	double factor;

	/**
	 * 技术人员构造函数
	 * @param name   姓名
	 * @param id     职工号
	 * @param hours  当月工作时数
	 * @param mph    每小时附加酬金
	 * @param factor 研究完成进度系数
	 */
	public Technician(String name,int id,double basic,double hours, double mph, double factor) {
		super(name,id,basic);
		this.hours = hours;
		this.moneyPerHour=mph;
		this.factor = factor;
	}

	@Override
	public void pay() {
		super.pay();
		this.performance=moneyPerHour*hours*factor;
		this.salary=basic+performance;
		sum+=salary;
	}
	
}
