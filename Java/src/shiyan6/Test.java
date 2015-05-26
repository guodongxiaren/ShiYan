package shiyan6;


public class Test {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try {
			method();
			System.out.println("After the method call");
		} catch (RuntimeException ex) {
			// TODO Auto-generated catch block
			System.out.println("RuntimeException in main");
		} catch (Exception ex) {
			System.out.println("Exception in main");
		}
	}

	static void method() throws Exception {
		try {
			Circle c1 = new Circle(1);
			c1.setRadius(-1);
			System.out.println(c1.getRadius());
		} catch (RuntimeException ex) {
			System.out.println("RuntimeException in method()");
		} catch (Exception ex) {
			System.out.println("Exception in method()");
			throw ex;
		}
	}
}
