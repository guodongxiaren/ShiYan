package shiyan5.jiekou;

import java.util.Date;

public interface GeometricObject {
	public String getColor();

	public void setColor(String color);

	public boolean isFilled();

	public void setFilled(boolean filled);

	public Date getDateCreated();

	/** Return a string representation of this object */
	public String toString();

	/** Abstract method getArea */
	public abstract double getArea();

	/** Abstract method getPerimeter */
	public abstract double getPerimeter();
}
