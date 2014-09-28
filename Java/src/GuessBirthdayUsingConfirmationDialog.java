import javax.swing.JOptionPane;
public class GuessBirthdayUsingConfirmationDialog {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String set1=
				" 1  3  5  7\n"+
                " 9 11 13 15\n"+
                "17 19 21 23\n"+
                "25 27 29 31\n";
		String set2=
				" 2  3  6  7\n"+
                "10 11 14 15\n"+
                "18 19 22 23\n"+
                "26 27 30 31\n";
		String set3=
				" 4  5  6  7\n"+
                "12 13 14 15\n"+
                "20 21 22 23\n"+
                "28 29 30 31\n";
		String set4=
				" 8  9 10 11\n"+
                "12 13 14 15\n"+
                "24 25 26 27\n"+
                "28 29 30 31\n";
		String set5=
				"16 17 18 19\n"+
                "20 21 22 23\n"+
                "24 25 26 27\n"+
                "28 29 30 31\n";
        int day=0;
        int answer = JOptionPane.showConfirmDialog(null,
                "Is your birthday in these numbers?\n"+set1);
        if(answer==JOptionPane.YES_OPTION)
            day+=1;
        answer = JOptionPane.showConfirmDialog(null,
                "Is your birthday in these numbers?\n"+set2);
        if(answer==JOptionPane.YES_OPTION)
            day+=2;
        answer = JOptionPane.showConfirmDialog(null,
                "Is your birthday in these numbers?\n"+set3);
        if(answer==JOptionPane.YES_OPTION)
            day+=4;
        answer = JOptionPane.showConfirmDialog(null,
                "Is your birthday in these numbers?\n"+set4);
        if(answer==JOptionPane.YES_OPTION)
            day+=8;
        answer = JOptionPane.showConfirmDialog(null,
                "Is your birthday in these numbers?\n"+set5);
        if(answer==JOptionPane.YES_OPTION)
            day+=16;
        JOptionPane.showMessageDialog(null,"Your birthday is "+day+"!");
	}

}
