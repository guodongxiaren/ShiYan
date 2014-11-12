package shiyan6.idcard;

public class Check {
	private String code;
	private String error;
	// 每月天数。二月在下面特殊计算
	private static int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30,31 };
	// 网上找的身份证前17位的权值
	private static int weight[] = { 7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5,8, 4, 2, 1 };
	//每一位数字所对应的校验码
	private static char chkcode[] = { '1', '0', 'X', '9', '8', '7', '6', '5','4', '3', '2' };
	private int year;
	private int mon;
	private int day;
	private boolean old;

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
		Check c = new Check("130922199310173618");
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
		// sub截取身份证号的地址部分
		String sub = code.substring(0, 6);
		QuYu qy = new QuYu(sub);
		System.out.println(qy.getAddress());
		// sub截取身份证号的生日部分
		sub = old ? code.substring(6, 12) : code.substring(6, 14);
		if (!trueBirth(sub)) {
			error = "出生日期错误";
			return false;
		}
		System.out.println(year + "年" + mon + "月" + day + "日");
		if (checkCode() == code.charAt(17)) {
			error = "校验码有误";
			return false;
		}

		return true;
	}

	/**
	 * 判断生日的真假
	 */
	private boolean trueBirth(String birthday) {
		String tmp;
		if (old == true) {
			tmp = "19" + birthday.substring(0, 2);
			year = Integer.parseInt(tmp);
			tmp = birthday.substring(2);
		} else {
			tmp = birthday.substring(0, 4);
			year = Integer.parseInt(tmp);
			tmp = birthday.substring(4);
		}
		mon = Integer.parseInt(tmp.substring(0, 2));
		if (mon > 12)
			return false;
		day = Integer.parseInt(tmp.substring(2));
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
}
