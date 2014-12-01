package shiyan7;

import java.awt.BorderLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.UIManager;
import javax.swing.UnsupportedLookAndFeelException;

import com.sun.java.swing.plaf.windows.WindowsLookAndFeel;

/**
 * 单步计算的计算器 王维
 */
@SuppressWarnings("serial")
public class Counter extends JFrame {

	private double num1;
	private double num2;
	private char oper;
	private boolean enableOper = true;
	private boolean start=true;
	// GUI对象
	private JButton jb[] = new JButton[10];
	private JTextField field;

	public Counter() {
		field = new JTextField();
		add(field, BorderLayout.NORTH);
		JPanel pa = new JPanel(new GridLayout(4, 4, 8, 8));
		JButton jbc = new JButton("C");
		JButton jbdiv = new JButton("/");
		JButton jbmul = new JButton("*");
		JButton jback = new JButton("←");
		JButton jbsub = new JButton("-");
		JButton jbadd = new JButton("+");
		JButton jbeq = new JButton("=");
		JButton jbdigt = new JButton(".");
		// 创建数字按钮对象，并添加监听器
		for (int i = 0; i <= 9; i++) {
			jb[i] = new JButton(i + "");
			jb[i].addActionListener(new DigitListener(i));
		}
		// 运算符按钮添加监听器
		jbmul.addActionListener(new OperListener('*'));
		jbdiv.addActionListener(new OperListener('/'));
		jbadd.addActionListener(new OperListener('+'));
		jbsub.addActionListener(new OperListener('-'));
		// 小数点按钮添加监听器
		jbdigt.addActionListener(new PointListener('.'));
		jbeq.addActionListener(new EqualListenr());
		// 开始布局
		pa.add(jb[7]);
		pa.add(jb[8]);
		pa.add(jb[9]);
		pa.add(jbadd);
		pa.add(jb[4]);
		pa.add(jb[5]);
		pa.add(jb[6]);
		pa.add(jbsub);
		pa.add(jb[1]);
		pa.add(jb[2]);
		pa.add(jb[3]);
		pa.add(jbmul);
		pa.add(jb[0]);
		pa.add(jbdigt);
		pa.add(jbeq);
		pa.add(jbdiv);

		add(pa, BorderLayout.CENTER);

	}

	public String calc() {
		String expr = field.getText();
		oper = 0;
		for (int i = 0; i < expr.length(); i++) {
			char c = expr.charAt(i);
			if (isOper(c)) {
				oper = c;
				num1 = Double.parseDouble(expr.substring(0, i));
				num2 = Double.parseDouble(expr.substring(i + 1));
			}
		}
		switch (oper) {
		case '+':
			num1 = num1 + num2;
			break;
		case '-':
			num1 = num1 - num2;
			break;
		case '*':
			num1 = num1 * num2;
			break;
		case '/':
			num1 = num1 / num2;
			break;
		}
		System.out.println(num1);
		// enableOper = true;
		return num1 + "";

	}

	private boolean isOper(char op) {
		if (op == '+' || op == '-' || op == '*' || op == '/')
			return true;
		return false;
	}

	public static void main(String[] args) {
		try {
			UIManager.setLookAndFeel(new WindowsLookAndFeel());
		} catch (UnsupportedLookAndFeelException e) {
			e.printStackTrace();
		}
		Counter c = new Counter();
		c.setSize(250, 250);
		c.setDefaultCloseOperation(EXIT_ON_CLOSE);
		c.setLocationRelativeTo(null);
		c.setVisible(true);
	}

	class DigitListener implements ActionListener {

		private int num;

		public DigitListener(int num) {
			this.num = num;
		}

		@Override
		public void actionPerformed(ActionEvent e) {
			if(start==false)
			field.setText(field.getText().concat(num + ""));
			// enableOper = true;
			else
				{
				field.setText(num+"");
				start = false;
				}
		}

	}

	class OperListener implements ActionListener {
		private char op;

		public OperListener(char op) {
			this.op = op;
		}

		@Override
		public void actionPerformed(ActionEvent e) {
			if (!enableOper || field.getText().equals(""))
				return;
			calc();
			if (oper == 0)
				field.setText(field.getText().concat(op + ""));
			else
				field.setText(calc().concat(op + ""));
			// enableOper = false;
		}

	}

	class PointListener implements ActionListener {
		private char ch;

		public PointListener(char ch) {
			this.ch = ch;
		}

		@Override
		public void actionPerformed(ActionEvent e) {
			field.setText(field.getText().concat(ch + ""));

		}

	}

	class EqualListenr implements ActionListener {

		@Override
		public void actionPerformed(ActionEvent e) {
			field.setText(calc());
			start=true;
		}

	}
}
