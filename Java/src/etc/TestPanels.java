package etc;

import java.awt.BorderLayout;
import java.awt.GridLayout;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.UIManager;
import javax.swing.UnsupportedLookAndFeelException;
import javax.swing.plaf.nimbus.NimbusLookAndFeel;

public class TestPanels extends JFrame{


	private static final long serialVersionUID = 1L;
	public TestPanels(){
		JPanel p1 = new JPanel();
		p1.setLayout(new GridLayout(4,3));
		
		for(int i=1;i<=9;i++){
			p1.add(new JButton(""+i));
		}
		p1.add(new JButton(""+0));
		p1.add(new JButton("Start"));
		p1.add(new JButton("Stop"));
		
		JPanel p2 = new JPanel(new BorderLayout());
		p2.add(new JTextField("Time to be displayed herd"),BorderLayout.NORTH);
		p2.add(p1,BorderLayout.CENTER);
		
		add(p2,BorderLayout.EAST);
		add(new JButton("Food to be placed here"),BorderLayout.CENTER);
		
	}
	public static void main(String[] args) {
		try {
			UIManager
			.setLookAndFeel(new NimbusLookAndFeel());
		} catch (UnsupportedLookAndFeelException e) {
			e.printStackTrace();
		}
		TestPanels frame = new TestPanels();
		frame.setTitle("The Front View of a Microwave Oven)");
		frame.setSize(400,250);
		frame.setLocationRelativeTo(null);
		frame.setVisible(true);

	}

}
