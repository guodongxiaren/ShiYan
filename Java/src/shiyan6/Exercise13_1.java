package shiyan6;

public class Exercise13_1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		if(args.length!=3){
			System.out.println("Please use Exercise13_1 operand1 operator operand2");
			return;
		}
		String op1=args[1];
		String op=args[2];
		String op2=args[3];
		double a,b;
		try{
			a =Double.parseDouble(op1);
		}catch(Exception e){
			System.out.println("Wrong Input: "+op1);
			return;
		}
		try{
			 b =Double.parseDouble(op2);
		}catch(Exception e){
			System.out.println("Wrong Input: "+op2);
			return;
		}
	switch(op.charAt(0)){
		case '+':System.out.println(a+b);break;
		case '-':System.out.println(a-b);break;
		case '*':System.out.println(a*b);break;
		case '/':System.out.println(a/b);break;
	}
	}

}
