package shiyan3;
class Point{
	private double x;
	private double y;
	public double getX() {
		return x;
	}
	public void setX(double x) {
		this.x = x;
	}
	public double getY() {
		return y;
	}
	public void setY(double y) {
		this.y = y;
	}
}
public class PointTest {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Point a = new Point();
		a.setX(10);
		a.setY(20);
		System.out.println("该点的坐标为("+a.getX()+" , "+a.getY()+")");
		a.setX(30.5);
		a.setY(55.3);
		System.out.println("该点的坐标为("+a.getX()+" , "+a.getY()+")");
	}

}
