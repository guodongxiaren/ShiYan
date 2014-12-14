package shiyan8;

import java.util.Random;

public class LivingCast2 {

	private double cast;

	public static void main(String[] args) {
		LivingCast2 livingCast = new LivingCast2();
		livingCast.new Parent().start();
		livingCast.new Child().start();
	}

	class Parent extends Thread {

		@Override
		public synchronized void run() {
			super.run();
			while (true) {
				if (cast != 0.0) {
					System.out.println("账户有余额，不存钱");
					continue;
				} else {
					Random r = new Random();
					double var = r.nextInt(10000);
					cast += var;
					System.out.println("家长存入了" + var + "元。当前余额" + cast + "元");
				}
				try {
					sleep(5000);
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
			}
		}

	}

	class Child extends Thread {

		@Override
		public synchronized void run() {
			super.run();
			while (true) {
				Random r = new Random();
				if (cast == 0.0) {
					System.out.println("没钱了，通知家长");
					continue;
				} else {
					double var = r.nextInt(2000);
					if (var > cast)
						var = cast;
					cast -= var;
					System.out.println("学生取出了" + var + "元。当前余额" + cast + "元");
				}
				try {
					sleep(1000);
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
			}
		}

	}
}
