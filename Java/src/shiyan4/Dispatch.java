package shiyan4;

class A {
	void callme() {
		System.out.println("Inside A's callme()method");
	}
}

class B extends A {
	void callme() {
		System.out.println("Inside B's callme() Method");
	}
}

public class Dispatch {
	public static void main(String args[]) {
		A a = new B();
		a.callme();
	}
}