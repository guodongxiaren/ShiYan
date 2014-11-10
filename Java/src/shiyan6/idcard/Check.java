package shiyan6.idcard;

public class Check {
	private String code;
	private String error;
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
public static void main(String args[]){
	Check c = new Check("440524198001010013");
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
		String sub = code.substring(0, 6);
		QuYu qy = new QuYu(sub);
		System.out.println(sub);
		System.out.print(qy.getAddress());

		return true;
	}

}
