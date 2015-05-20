package shiyan5.jiekou;

import java.util.Date;

public class Circle implements GeometricObject {
	private String color = "white";
	private boolean filled;
	private java.util.Date dateCreated;
	private double radius;

	public Circle() {
		dateCreated = new java.util.Date();

	}

	public Circle(double radius) {

	}

	public String getColor() {
		// TODO Auto-generated method stub
		return color;
	}

	public void setColor(String color) {
		// TODO Auto-generated method stub
		this.color = color;
	}

	public boolean isFilled() {
		// TODO Auto-generated method stub
		return filled;
	}

	public void setFilled(boolean filled) {
		// TODO Auto-generated method stub
		this.filled = filled;
	}

	public Date getDateCreated() {
		// TODO Auto-generated method stub
		return dateCreated;
	}

	public double getArea() {
		// TODO Auto-generated method stub
		return radius * radius * Math.PI;
	}

	public double getPerimeter() {
		// TODO Auto-generated method stub
		return 2 * radius * Math.PI;
	}

	public double getRadius() {
		return radius;
	}

	public void setRadius(double radius) {
		this.radius = radius;
	}
}
