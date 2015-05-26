package shiyan6;

public class Exercise13_01 {

	public static void main(String[] args) {
		if (args.length != 3) {
			System.out
					.println("Please use Exercise13_1 operand1 operator operand2");
			return;
		}
		String op1 = args[0];
		String op = args[1];
		String op2 = args[2];
		double a, b;
		if (isNum(op1) == false) {
			System.out.println("Wrong Input: " + op1);
			return;
		}
		if (isNum(op2) == false) {
			System.out.println("Wrong Input: " + op2);
			return;
		}
		a = Double.parseDouble(op1);
		b = Double.parseDouble(op2);
		System.out.print(a + " " + op + " " + b + " = ");
		switch (op.charAt(0)) {
		case '+':
			System.out.println(a + b);
			break;
		case '-':
			System.out.println(a - b);
			break;
		case '*':
			System.out.println(a * b);
			break;
		case '/':
			System.out.println(a / b);
			break;
		}
	}

	static boolean isNum(String a) {
		for (int i = 0; i < a.length(); i++) {
			char c = a.charAt(i);
			if ('0' <= c && c <= '9')
				continue;
			else if (c == '.' && (i != 0 || i != a.length() - 1))
				continue;
			else
				return false;
		}
		return true;
	}

}
