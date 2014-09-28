package shiyan3;

public class Complex {
	private double real;
	private double imaginary;
	public void plus(Complex a){
		this.real+=a.getReal();
		this.imaginary+=a.getImaginary();
		System.out.println("相加之后，变为"+real+imaginary+"i");
	}
	public void sub(Complex a){
		this.real-=a.getReal();
		this.imaginary-=a.getImaginary();
		System.out.println("相减之后，变为"+real+imaginary+"i");
	}
	public void plus(double a){
		this.real+=a;
		System.out.println("相加之后，变为"+real+imaginary+"i");
	}
	public void sub(double a){
		this.real-=a;
		System.out.println("相减之后，变为"+real+imaginary+"i");
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
		a.plus(b);
		a.sub(a);
		a.plus(12);
		a.sub(10);
	}

}
