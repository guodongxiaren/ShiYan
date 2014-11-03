package shiyan5.jiekou;

public interface GeometricObject {
	
	/** Return a string representation of this object */
	public String toString() ;
	/** Abstract method getArea */
	public abstract double getArea();
	/** Abstract method getPerimeter */
	public abstract double getPerimeter();
}
