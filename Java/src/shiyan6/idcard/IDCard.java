package shiyan6.idcard;

import java.awt.BorderLayout;
import java.awt.GridLayout;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class IDCard extends JFrame {
	public IDCard(){
		JPanel p = new JPanel();
		p.add(new JLabel("请输入身份证号："));
		JTextField num=new JTextField(18);
		p.add(num);
		JButton ok = new JButton("确定");
		p.add(ok);
		add(p,BorderLayout.NORTH);
		JPanel p2 = new JPanel();
		p2.setLayout(new GridLayout(3, 2, 5, 5));
		p2.add(new JLabel("性别"));
		JTextField t1 = new JTextField(10);
		t1.setEnabled(false);
		p2.add(t1);
		p2.add(new JLabel("出生日期"));
		JTextField t2 = new JTextField(8);
		t2.setEnabled(false);
		p2.add(t2);
		p2.add(new JLabel("地址"));
		JTextField t3 = new JTextField(8);
		t3.setEnabled(false);
		p2.add(t3);
		add(p2,BorderLayout.CENTER);
	}
	public static void main(String[] args) {
		IDCard idcard = new IDCard();
		idcard.setSize(500,300);
		idcard.setLocationRelativeTo(null);
		idcard.setDefaultCloseOperation(EXIT_ON_CLOSE);
		idcard.setVisible(true);
	}

}
