package shiyan8;

import java.util.Random;

public class LivingCast1 {

	private double cast;

	public static void main(String[] args) {
		LivingCast1 livingCast = new LivingCast1();
		livingCast.new Parent().start();
		livingCast.new Child().start();
	}

	class Parent extends Thread {

		@Override
		public void run() {
			super.run();
			while (true) {
				double var = Math.random() * 10000;
				cast += var;
				System.out.println("家长存入了" + var + "元。当前余额" + cast + "元");
				try {
					sleep(1000);
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
			}
		}

	}

	class Child extends Thread {

		@Override
		public void run() {
			super.run();
			while (true) {
				Random r = new Random();
				if (cast == 0.0)
					continue;
				double var = r.nextInt((int) cast);
				cast -= var;
				System.out.println("学生取出了" + var + "元。当前余额" + cast + "元");
				try {
					sleep(1000);
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
			}
		}

	}
}
