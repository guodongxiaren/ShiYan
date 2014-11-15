package shiyan2;
import java.util.Scanner;

public class Convert {
	public static final char unit[] = { '分','角', '元', '拾', '佰', '仟', '萬' };
	public static final char num[] = { '零', '壹', '贰', '叁', '肆', '伍', '陆', '柒', '捌',
			'玖' };

	public static void main(String[] args) {
		System.out.print("请输入一个数（最多两位小数）:");
		Scanner sc = new Scanner(System.in);
		float f = sc.nextFloat();
		if (f >=100000) {
			System.out.println("超出范围");
			sc.close();
			return;
		}
		f *= 100;
		int r = (int) f;
		int offset = 0;
		if (r % 100 == 0)
			offset = 2;
		else if (r % 10 == 0)
			offset = 1;
		String fs = String.valueOf(r);
		int len = fs.length();
		int index = len - 1;
		len -= offset;
		boolean flag = false;
		for (int i = 0; i < len; i++, index--) {
			char ch = fs.charAt(i);
			if (ch == '0') {
				flag = true;
				if (index == 2 || index == 1)
					flag = false;
				else
					continue;
			}
			if (flag)
				System.out.print("零");
			if (ch != '0')
				System.out.print(num[ch - '0']);
			if (ch != '0' || index != 1)
				System.out.print(unit[index]);
		}
		if (offset == 2)
			System.out.println("整");
		else
			System.out.println();
		sc.close();
	}
}