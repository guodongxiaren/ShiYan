package shiyan4;

/*
 * 设计两个类（一个父类、一个子类），测试并总结子类和父类中静态块和动态块、构造函数的调用顺序。
 */
class Parent {
	{
		System.out.println("父类动态块");
	}
	static {
		System.out.println("父类的静态块");
	}

	public Parent() {
		System.out.println("父类的构造函数");
	}
}

class Child extends Parent {
	{
		System.out.println("子类动态块");
	}
	static {
		System.out.println("子类的静态块");
	}

	public Child() {
		System.out.println("子类的构造函数");
	}
}

public class Test {

	public static void main(String[] args) {
		@SuppressWarnings("unused")
		Child c = new Child();
	}
}
