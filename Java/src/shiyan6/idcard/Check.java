package shiyan6.idcard;

public class Check {
	private String code;
	private String quyu;
	private String error;
	// 每月天数。二月在下面特殊计算
	private static int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30,
			31 };
	// 网上找的身份证前17位的权值
	private static int weight[] = { 7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5,
			8, 4, 2, 1 };
	// 每一位数字所对应的校验码
	private static char chkcode[] = { '1', '0', 'X', '9', '8', '7', '6', '5',
			'4', '3', '2' };
	private int year;
	private int mon;
	private int day;
	private boolean old;
	// 男为true，女为false
	private boolean sex;

	public Check(String code) {
		this.code = code;
	}

	public String getCode() {
		return code;
	}

	public String getError() {
		return error;
	}

	public void setError(String error) {
		this.error = error;
	}

	public void setCode(String code) {
		this.code = code;
	}

	public static void main(String args[]) {
		Check c = new Check("930922199310173618");
		c.isTrue();
	}

	public boolean isTrue() {
		if (code.length() == 15)
			old = true;
		else if (code.length() == 18)
			old = false;
		else {
			error = "身份证号长度错误";
			return false;
		}
		if (!trueQuYu()) {
			error = "区域码错误";
			return false;
		}
		if (!trueBirth()) {
			error = "出生日期错误";
			return false;
		}
		if (!old && checkCode() != code.charAt(17)) {
			error = "校验码有误";
			return false;
		}
		if (!checkSex()) {
			error = "顺序码有误";
			return false;
		}
		System.out.println(quyu);
		System.out.println(year + "年" + mon + "月" + day + "日");
		System.out.println(sex ? "男" : "女");
		return true;
	}

	/*
	 * 判断区域码真假，并得出出生地址
	 */
	private boolean trueQuYu() {
		// sub截取身份证号的地址部分
		String sub = code.substring(0, 6);
		QuYu qy = new QuYu(sub);
		quyu = qy.getAddress();
		if (quyu == null)
			return false;
		return true;
	}

	/**
	 * 判断生日的真假
	 */
	private boolean trueBirth() {
		String birthday = old ? code.substring(6, 12) : code.substring(6, 14);
		int date;
		if (old == true)
			birthday = "19" + birthday;
		try {
			date = Integer.parseInt(birthday);
		} catch (NumberFormatException e) {
			return false;
		}
		year = date / 10000;
		mon = (date % 10000) / 100;
		day = date % 100;
		if (mon > 12)
			return false;
		int run = 0;// 是不是闰年，用整型来表示，方便下面作加法
		if (year % 4 == 0 && year % 400 != 0)
			run = 1;
		if (mon == 2) {
			if (day > days[2] + run)
				return false;
		} else if (day > days[mon - 1])// 如果不在该月天数的范围内，则为假生日
			return false;
		return true;
	}

	/*
	 * 求校验码
	 */
	private char checkCode() {
		int sum = 0;
		for (int i = 0; i < 17; i++) {
			int a = code.charAt(i) - '0';
			int w = weight[i];
			sum += a * w;
		}
		sum %= 11;
		return chkcode[sum];
	}

	/*
	 * 计算性别
	 */
	private boolean checkSex() {
		String tmp;
		if (old)
			tmp = code.substring(12);
		else
			tmp = code.substring(14, 17);
		try {
			int seq = Integer.parseInt(tmp);
			// 判断奇偶
			if ((seq & 1) == 1)
				sex = true;
			else
				sex = false;
		} catch (NumberFormatException e) {
			return false;
		}
		return true;
	}
}
