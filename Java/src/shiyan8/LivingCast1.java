package shiyan8;

import java.util.Random;

public class LivingCast1 implements Cast {

	private double cast;

	public static void main(String[] args) {
		LivingCast1 livingCast = new LivingCast1();
		Parent p = new Parent(livingCast);
		Child c = new Child(livingCast);
		p.start();
		c.start();
	}

	@Override
	public void saveMoney() {
		while (true) {
			Random r = new Random();
			double var = (double) r.nextInt(10000);
			cast += var;
			System.out.println("家长存入了" + var + "元。当前余额" + cast + "元");
			try {
				Thread.sleep(1000);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}

	}

	@Override
	public void takeMoney() {
		while (true) {
			Random r = new Random();
			if (cast == 0.0)
				continue;
			double var = r.nextInt((int) cast);
			cast -= var;
			System.out.println("学生取出了" + var + "元。当前余额" + cast + "元");
			try {
				Thread.sleep(1000);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}

	}
}
