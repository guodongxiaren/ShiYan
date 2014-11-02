package shiyan5.jiekou;

public interface GeometricObject {
	public String color = "white";
	public  boolean filled=false;
	public  java.util.Date dateCreated = new java.util.Date();
	
	/** Return color */
	public String getColor();
	/** Set a new color */
	public void setColor(String color);
	/** Return filled. Since filled is boolean,
	* the get method is named isFilled */
	public boolean isFilled();
	/** Set a new filled */
	public void setFilled(boolean filled);
	/** Get dateCreated */
	public java.util.Date getDateCreated();
	/** Return a string representation of this object */
	public String toString() ;
	/** Abstract method getArea */
	public abstract double getArea();
	/** Abstract method getPerimeter */
	public abstract double getPerimeter();
}
