package shiyan5;

public class TestSquare {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		GeometricObject objects[] = new Square[5];
		objects[0] = new Square(1);
		objects[1] = new Square(1.5, "red");
		objects[2] = new Square(2.5);
		objects[3] = new Square(3.0, "black");
		objects[4] = new Square(5);
		for (int i = 0; i < 5; i++) {
			System.out.println("第" + i + "对象：");
			if (objects[i].isFilled()) {
				((Colorable) objects[i]).howToColor();
			} else
				System.out.println("不可着色");
			System.out.println("面积为：" + objects[i].getArea());
			System.out.println("周长为：" + objects[i].getPerimeter());
		}
	}

}
