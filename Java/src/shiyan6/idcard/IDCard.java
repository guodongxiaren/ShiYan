package shiyan6.idcard;

import java.awt.BorderLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JSeparator;
import javax.swing.JTextField;
import javax.swing.UIManager;
import javax.swing.UnsupportedLookAndFeelException;
import javax.swing.plaf.nimbus.NimbusLookAndFeel;

@SuppressWarnings("serial")
public class IDCard extends JFrame {
	private JPanel p,p2;
	private JTextField num, tBirth, tSex, tType, tAddress,tNew;
	private JLabel lnew;
	public IDCard() {
		p = new JPanel();
		p.add(new JLabel("请输入身份证号："));
		num = new JTextField(18);
		p.add(num);
		JButton ok = new JButton("确定");
		ok.addActionListener(new OKListener());
		p.add(ok);
		add(p, BorderLayout.NORTH);
		p2 = new JPanel();
		p2.setLayout(new GridLayout(5, 2, 5, 5));
		p2.add(new JLabel("身份证类型",JLabel.CENTER));
		tType = new JTextField(2);
		//设置文本区不能聚焦，使之无法编辑
		tType.setFocusable(false);
		p2.add(tType);
		p2.add(new JLabel("性别",JLabel.CENTER));
		tSex = new JTextField();
		tSex.setFocusable(false);
		p2.add(tSex);
		p2.add(new JLabel("出生日期",JLabel.CENTER));
		tBirth = new JTextField();
		tBirth.setFocusable(false);
		p2.add(tBirth);
		p2.add(new JLabel("地址",JLabel.CENTER));
		tAddress = new JTextField();
		tAddress.setFocusable(false);
		p2.add(tAddress);
		lnew = new JLabel("新身份证号",JLabel.CENTER);
		lnew.setVisible(false);
		p2.add(lnew);
		tNew = new JTextField();
		tNew.setFocusable(false);
		tNew.setVisible(false);
		p2.add(tNew);
		add(new JSeparator(), BorderLayout.CENTER);
		add(p2, BorderLayout.SOUTH);
	}

	public static void main(String[] args)
			throws UnsupportedLookAndFeelException {
		UIManager
				.setLookAndFeel(new NimbusLookAndFeel());
		IDCard idcard = new IDCard();
		idcard.setResizable(false);
		idcard.setSize(400, 250);
		idcard.setLocationRelativeTo(null);
		idcard.setDefaultCloseOperation(EXIT_ON_CLOSE);
		idcard.setVisible(true);
	}

	class OKListener implements ActionListener {

		public void actionPerformed(ActionEvent e) {
			String code;
			code = num.getText();
			//去掉身份证号码前后的多余空格
			code=code.trim();
			num.setText(code);
			Check c = new Check(code);
			//如果是假身份证，弹出错误消息对话框
			if (!c.isTrue()) {
				clear();
				JOptionPane.showMessageDialog(null, c.getError(),"假身份证", JOptionPane.ERROR_MESSAGE);
				return;
			}
			tType.setText(c.isType() ? "旧" : "新");
			tSex.setText(c.isSex() ? "男" : "女");
			tBirth.setText(c.getYear() + "年" + c.getMon() + "月" + c.getDay()
					+ "日");
			tAddress.setText(c.getAddress());
			if (c.isType()) {
				lnew.setVisible(true);
				tNew.setText(c.toNewCode());
				tNew.setVisible(true);
			}else{
				lnew.setVisible(false);
				tNew.setVisible(false);
			}
		}
		/*
		 *清空面板上的身份信息。仅当身份证号为假时，调用。 
		 */
		private void clear(){
			tBirth.setText("");
			tSex.setText("");
			tType.setText("");
			tAddress.setText("");
			tNew.setText("");
		}
	}

}
