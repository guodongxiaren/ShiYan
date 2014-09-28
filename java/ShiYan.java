import java.util.Scanner;
public class ShiYan{
        public static String unit[] = { "分", "角", "元", "拾", "佰", "仟", "萬"  };
            public static char num[] = { '零', '壹', '贰', '叁', '肆', '伍', '陆', '柒', '捌',
                        '玖' };
    public static void main(String[]args){
        Scanner sc = new Scanner(System.in);
        String money=sc.nextLine();
        int index=money.indexOf(".");
        String inte="",digt="";
        if(index!=-1)
        {
            inte=money.substring(0,index);
            digt=money.substring(index+1);
        }
        System.out.println(inte);
        System.out.println(digt);
        int len=inte.length();
        int p=len+1;
        boolean flag=false;
        for(int i=0;i<len;i++)
        {
            char ch=inte.charAt(i);
            if(ch=='0')
            {
                flag=true;
                if(p==2||p==6)
                    flag=false;
                else
                    continue;
            }
            if(flag)
                System.out.print(num[0]);
            if(ch!='0')
                System.out.print(num[ch-'0']);
            if(ch!=0)
                System.out.print(unit[p]);
            else if(index==2||index==6)
                System.out.print(unit[p]);
            p--;
        }
    }
}
