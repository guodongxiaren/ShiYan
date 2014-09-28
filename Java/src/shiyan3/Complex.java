package shiyan3;

public class Complex {
	private double real;
	private double imaginary;
	public void plus(Complex a){
		System.out.println(this.real+"+"+this.imaginary+"i 和"+a.real+"+"+a.imaginary+"i ");
		this.real+=a.getReal();
		this.imaginary+=a.getImaginary();
		System.out.println("相加之后，变为"+real+"+"+imaginary+"i");
	}
	public void minus(Complex a){
		System.out.println(this.real+"+"+this.imaginary+"i 和"+a.real+"+"+a.imaginary+"i ");
		this.real-=a.getReal();
		this.imaginary-=a.getImaginary();
		System.out.println("相减之后，变为"+real+"+"+imaginary+"i");
	}
	public void plus(double a){
		System.out.println(this.real+"+"+this.imaginary+"i 和"+a);
		this.real+=a;
		System.out.println("相加之后，变为"+real+"+"+imaginary+"i");
	}
	public void minus(double a){
		System.out.println(this.real+"+"+this.imaginary+"i 和"+a);
		this.real-=a;
		System.out.println("相减之后，变为"+real+"+"+imaginary+"i");
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
		a.plus(b);
		a.minus(c);
		a.plus(12);
		a.minus(10);
	}

}
