package shiyan5;

public class Square extends GeometricObject implements Colorable {

	private double length;

	public Square(double length){
		super();
		this.length=length;
	}
	public Square(double length,String color){
		super(color,true);
		this.length=length;
	}
	public void howToColor() {
		// TODO Auto-generated method stub
        System.out.println("Color all four sides");
	}
public void xx(){}
	@Override
	public double getArea() {
		// TODO Auto-generated method stub
		return length*length;
	}

	@Override
	public double getPerimeter() {
		// TODO Auto-generated method stub
		return 4*length;
	}

}
