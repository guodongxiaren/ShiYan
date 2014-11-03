package shiyan5.jiekou;

import java.util.Date;

public class Rectangle implements GeometricObject {
	private String color = "white";
	private boolean filled;
	private java.util.Date dateCreated;
	private double width;
	private double height;

	public Rectangle() {
		dateCreated = new java.util.Date();
	}

	public Rectangle(double width, double height) {
		this.width = width;
		this.height = height;
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
		return width * height;
	}

	public double getPerimeter() {
		// TODO Auto-generated method stub
		return 2 * (width + height);
	}

	public double getWidth() {
		return width;
	}

	public void setWidth(double width) {
		this.width = width;
	}

	public double getHeight() {
		return height;
	}

	public void setHeight(double height) {
		this.height = height;
	}

}
