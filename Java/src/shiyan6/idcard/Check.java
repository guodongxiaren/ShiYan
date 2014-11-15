package shiyan6.idcard;

public class Check {
	private String code;
	private String address;
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
	//身份证的类型，旧身份证为true，新身份证为false
	private boolean type;
	// 男为true，女为false
	private boolean sex;

	public Check(String code) {
		this.code = code;
	}
	public String getError() {
		return error;
	}
	public void setCode(String code) {
		this.code = code;
	}

	public int getDay() {
		return day;
	}

	public String getAddress() {
		return address;
	}

	public int getYear() {
		return year;
	}

	public int getMon() {
		return mon;
	}

	public boolean isType() {
		return type;
	}
	public boolean isSex() {
		return sex;
	}

	public void setSex(boolean sex) {
		this.sex = sex;
	}
	public boolean isTrue() {
		if (code.length() == 15)
			type = true;
		else if (code.length() == 18)
			type = false;
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
		if (!type && checkCode(code) != code.charAt(17)) {
			error = "校验码有误";
			return false;
		}
		if (!checkSex()) {
			error = "顺序码有误";
			return false;
		}
		return true;
	}

	/*
	 * 判断区域码真假，并得出出生地址
	 */
	private boolean trueQuYu() {
		// sub截取身份证号的地址部分
		String sub = code.substring(0, 6);
		QuYu qy = new QuYu(sub);
		address = qy.getAddress();
		if (address == null)
			return false;
		return true;
	}

	/*
	 * 判断生日的真假
	 */
	private boolean trueBirth() {
		String birthday = type ? code.substring(6, 12) : code.substring(6, 14);
		int date;
		if (type == true)
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
	private char checkCode(String code) {
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
		if (type)
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
	public String toNewCode(){
	//使用StringBuffer实现字符串相加，更高效
		StringBuffer tmp = new StringBuffer(code.substring(0,6));
		tmp.append("19");
		tmp.append(code.substring(6));
		tmp.append(checkCode(tmp.toString()));
		return tmp.toString();
	}
	public static void main(String[]args){
		Check c = new Check("130922931017361");
		c.isTrue();
		c.toNewCode();
	}
}
