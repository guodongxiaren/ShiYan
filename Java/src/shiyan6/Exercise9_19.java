package shiyan6;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;

class WriteFile {
	private String name;

	public WriteFile(String name) {
		this.name = name;
	}

	public void writeFile() {
		File fi = new File(name);
		try {
			PrintWriter pw = new PrintWriter(fi);
			for (int i = 0; i < 100; i++) {
				int t = (int) (Math.random() * 10000);
				pw.print(t + "\n");
			}
			pw.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}
}

public class Exercise9_19 {

	public static void main(String[] args) {
		WriteFile wf = new WriteFile("Exercise9_19.txt");
		wf.writeFile();
	}
}
