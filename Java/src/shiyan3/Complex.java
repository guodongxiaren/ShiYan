package shiyan3;

public class Complex {
	private double real;
	private double imaginary;
	public Complex plus(Complex a){
		
		double x = this.real+a.getReal();
		double y = this.imaginary+a.getImaginary();
		Complex tmp = new Complex(x,y);
		return tmp;
	}
	public Complex minus(Complex a){

		double x = this.real-a.getReal();
		double y = this.imaginary-a.getImaginary();
		Complex tmp = new Complex(x,y);
		return tmp;
	}
	public Complex plus(double a){

		double x = this.real+a;
		double y = this.imaginary;
		Complex tmp = new Complex(x,y);
		return tmp;
	}
	public Complex minus(double a){
	
		double x = this.real-a;
		double y = this.imaginary;
		Complex tmp = new Complex(x,y);
		return tmp;
	}
	
	public String print() {
		// TODO Auto-generated method stub
		if(this.imaginary>0)
			return this.real+"+"+this.imaginary+"i";
		else if(this.imaginary<0)
			return this.real+""+this.imaginary+"i";
		else
			return this.real+"";
	}
	public double getReal() {
		return real;
	}
	public void setReal(double real) {
		this.real = real;
	}
	public double getImaginary() {
		return imaginary;
	}
	public void setImaginary(double imaginary) {
		this.imaginary = imaginary;
	}
	public Complex(){};
	public Complex(double real,double imaginary){
		this.real=real;
		this.imaginary=imaginary;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Complex a = new Complex(1,2);
		Complex b = new Complex(4,5);
		Complex c = new Complex(2,3);
		System.out.println(a+" 和"+b+"相加等于 "+ a.plus(b).print());
		System.out.println(a+" 和"+c+"相减等于 "+a.minus(c).print());
		System.out.println(a+" 和"+12+"相加等于 "+a.plus(12).print());
		System.out.println(a+" 和"+10+"相减等于 "+a.minus(10).print());
	
	}

}
