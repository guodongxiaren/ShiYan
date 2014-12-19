package shiyan7;

import java.awt.Font;

import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.UIManager;

import com.sun.java.swing.plaf.windows.WindowsLookAndFeel;

@SuppressWarnings("serial")
public class FileMenu extends JFrame {

	public FileMenu() {
		JMenuBar jmb = new JMenuBar();
		setJMenuBar(jmb);
		// 文件菜单项
		JMenu file = new JMenu("文件");
		JMenuItem newfile = new JMenuItem("新建");
		JMenuItem open = new JMenuItem("打开");
		JMenuItem close = new JMenuItem("关闭");
		JMenuItem exit = new JMenuItem("退出");
		file.add(newfile);
		file.add(open);
		file.add(close);
		file.add(exit);
		jmb.add(file);
		// 编辑菜单项
		JMenu edit = new JMenu("编辑");
		JMenuItem copy = new JMenuItem("复制");
		JMenuItem paste = new JMenuItem("粘贴");
		JMenuItem find = new JMenuItem("查找");
		JMenuItem replace = new JMenuItem("替换");
		JMenuItem locate = new JMenuItem("定位");
		edit.add(copy);
		edit.add(paste);
		edit.add(find);
		edit.add(replace);
		edit.add(locate);
		jmb.add(edit);
		// 格式菜单项
		JMenu format = new JMenu("格式");
		JMenuItem foreground = new JMenuItem("前景色");
		JMenuItem background = new JMenuItem("背景色");
		JMenuItem fontStyle = new JMenuItem("字体风格");
		JMenuItem fontFormat = new JMenuItem("字体格式");
		format.add(foreground);
		format.add(background);
		format.add(fontStyle);
		format.add(fontFormat);
		jmb.add(format);
		// 窗口菜单项
		JMenu window = new JMenu("窗口");
		jmb.add(window);
		// 帮助菜单项
		JMenu help = new JMenu("帮助");
		JMenuItem userHelp = new JMenuItem("用户帮助");
		JMenuItem version = new JMenuItem("版本说明");
		help.add(userHelp);
		help.add(version);
		jmb.add(help);

		setSize(400, 300);
		setLocationRelativeTo(null);
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		setVisible(true);
	}

	// main函数
	public static void main(String[] args) throws Exception {
		UIManager.setLookAndFeel(new WindowsLookAndFeel());
		UIManager.put("Menu.font", new Font("微软雅黑", Font.PLAIN, 15));
		new FileMenu();
	}

}
