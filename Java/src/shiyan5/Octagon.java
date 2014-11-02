package shiyan5;

public class Octagon extends GeometricObject implements Comparable<Octagon>,
		Cloneable {
 private double length;
public Octagon(double length) {

	this.length=length;
}
	@Override
	public double getArea() {

		return (2+4/Math.sqrt(2))*length*length;
	}

	@Override
	public double getPerimeter() {
		return 0;
	}
	public double getLength() {
	return length;
}

public void setLength(double length) {
	this.length = length;
}

	public int compareTo(Octagon o) {
		if(this.length>o.getLength())
			return 1;
		else if(this.length<o.getLength())
			return -1;
		else
			return 1;
			
	}

	@Override
	protected Object clone() throws CloneNotSupportedException {
		
		return super.clone();
	}

}
