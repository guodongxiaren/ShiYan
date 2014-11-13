package shiyan6.idcard;

import java.io.BufferedReader;
import java.io.FileReader;
import java.util.HashMap;
import java.util.Map;

public class QuYu {
	private Map<String,String> hm;
	//地址码
	private String addressCode;
	private String filename="/home/jelly/github/shiyan/id.txt";

	public QuYu(String name) {
		this.addressCode = name;
		hm = new HashMap<String, String>();
		readTxt();
	}

	@SuppressWarnings("resource")
	public boolean readTxt() {
		boolean flag = false;
		BufferedReader br = null;
		try {
			FileReader read = new FileReader(filename);
			br = new BufferedReader(read);
			String line;
			String tmp[] = new String[2];
			while ((line = br.readLine()) != null) {
				tmp = line.split(" ");
				hm.put(tmp[0], tmp[1]);
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
		return flag;
	}
	public String getAddress(){
		return (String)hm.get(addressCode);
	}
}
