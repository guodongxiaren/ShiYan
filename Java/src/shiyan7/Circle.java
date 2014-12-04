package shiyan7;

import javax.swing.JFrame;
import javax.swing.JPanel;

public class Circle extends JFrame {

	public Circle() {
		JPanel panel = new JPanel();
		add(panel);
		
		
		setSize(400,300);
		setLocationRelativeTo(null);
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		setVisible(true);
	}
	public static void main(String[] args) {
		new Circle();
	}

}
