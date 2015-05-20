package shiyan8;

class SimpleThread extends Thread {
	public SimpleThread(String str) {
		super(str); // 调用其父类的构造方法
	}

	public void run() { // 重写run方法
		for (int i = 0; i < 10; i++) {
			System.out.println(i + " " + getName());
			// 打印次数和线程的名字
			try {
				sleep((int) (Math.random() * 1000));
				// 线程睡眠，把控制权交出去
			} catch (InterruptedException e) {
			}
		}
		System.out.println("DONE! " + getName());
		// 线程执行结束
	}
}

public class TwoThreadsTest {
	public static void main(String args[]) {
		new SimpleThread("First").start();
		// 第一个线程的名字为First
		new SimpleThread("Second").start();
		// 第二个线程的名字为Second
	}
}
