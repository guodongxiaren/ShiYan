package shiyan3;

public class Role {
	//生命值
    private int life;
    //经验值
    private int exp;
    //交手的次数
    public static int num;
    //经验值增加50的基准
    private int expBase;
	public int getLife() {
		return life;
	}
	public void setLife(int life) {
		this.life = life;
	}
	public int getExp() {
		return exp;
	}
	public void setExp(int exp) {
		this.exp = exp;
	}
	public int getExpBase() {
		return expBase;
	}
	public void setExpBase(int expBase) {
		this.expBase = expBase;
	}
    public boolean fight(Role other){
    	num++;
    	life-=1;
    	exp+=2;
    	if(exp-expBase>=50){
    		life++;
    		expBase+=50;
    	}
    	other.setLife(other.getLife()-2);
    	other.setExp(other.getExp()+3);
    	if(other.getExp()-other.getExpBase()>=50){
    		other.setLife(other.getLife()+1);
    		other.setExpBase(other.getExpBase()+50);
    	}
    	System.out.println("第"+num+"次战斗开始");
    	if(life<=0&&life<=0)
    		{
    		System.out.println("战斗结束，两人打平");
    		return true;
    		}
    	else if(life<=0)
    		{
    		System.out.println("战斗结束，角色2获胜");
    		return true;
    		}
    	else if(other.getLife()<=0)
    		{
    		System.out.println("战斗结束，角色1获胜");
    		return true;
    		}
    	else{
    		System.out.println("    角色1的生命值为"+life+"，角色2的生命值为"+other.getLife());
    		System.out.println("    角色1的经验值为"+exp+"，角色2的经验值为"+other.getExp());
    		return false;
    	}
    }

	public Role(int life,int exp){
		this.life=life;
		this.exp=exp;
		this.expBase=exp;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Role a = new Role(1000,0);
		Role b = new Role(1000,0);
		//死循环，两人战斗，直到分出胜负为止
		while(!a.fight(b)){}
	}

}
