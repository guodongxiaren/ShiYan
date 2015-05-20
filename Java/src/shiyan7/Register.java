package shiyan7;

import java.awt.BorderLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Arrays;

import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JComponent;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JPasswordField;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.UIManager;
import javax.swing.border.EmptyBorder;

import com.sun.java.swing.plaf.windows.WindowsLookAndFeel;

@SuppressWarnings("serial")
public class Register extends JFrame {

	private JPanel p1, p2;

	private String[] fields = { "用户名", "密码", "确认密码", "性别", "出生年月" };
	private JButton jbOk, jbCancel;
	private JTextArea area;
	private JTextField nameField, dateField;
	private JComboBox<String> sexBox;
	private JPasswordField pwdField1, pwdField2;

	public Register() {
		p1 = new JPanel(new GridLayout(5, 2, 5, 5));
		p1.setBorder(new EmptyBorder(10, 30, 10, 10));
		p2 = new JPanel();
		nameField = new JTextField();
		pwdField1 = new JPasswordField();
		pwdField2 = new JPasswordField();
		String[] sexs = { "男", "女" };
		sexBox = new JComboBox<String>(sexs);
		dateField = new JTextField();
		JComponent[] compo = { nameField, pwdField1, pwdField2, sexBox,
				dateField };
		for (int i = 0; i < fields.length; i++) {
			JLabel label = new JLabel(fields[i]);
			p1.add(label);
			p1.add(compo[i]);
		}
		add(p1, BorderLayout.NORTH);
		jbOk = new JButton("确定");
		jbCancel = new JButton("取消");
		jbOk.addActionListener(new OkListener());
		p2.add(jbOk);
		p2.add(jbCancel);
		add(p2, BorderLayout.CENTER);
		area = new JTextArea(5, 2);
		area.setLineWrap(false);
		area.setEditable(false);
		add(area, BorderLayout.SOUTH);
	}

	// main函数
	public static void main(String[] args) throws Exception {
		UIManager.setLookAndFeel(new WindowsLookAndFeel());
		Register r = new Register();
		r.setVisible(true);
		r.setLocationRelativeTo(null);
		r.setSize(300, 350);

	}

	// 确定按钮的事件监听
	class OkListener implements ActionListener {

		@Override
		public void actionPerformed(ActionEvent e) {
			char[] pwd1 = pwdField1.getPassword();
			char[] pwd2 = pwdField2.getPassword();
			// Array类用来比较两个字符数组是否相同
			if (!Arrays.equals(pwd1, pwd2)) {
				JOptionPane.showMessageDialog(null, "两次密码不一致", "错误",
						JOptionPane.ERROR_MESSAGE);
			}
			area.setText(fields[0] + '\t');
			area.append(nameField.getText());
			area.append('\n' + fields[1] + '\t');
			area.append(new String(pwd1));
			area.append('\n' + fields[3] + '\t');
			area.append((String) sexBox.getSelectedItem());
			area.append('\n' + fields[4] + '\t');
			area.append(dateField.getText());
		}
	}
}
