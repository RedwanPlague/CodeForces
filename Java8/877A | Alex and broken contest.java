import java.util.Scanner;
import java.lang.*;
 
public class Codeforces877A {
    public static void main(String[] a) {
        String[] names = {"Danil", "Olya", "Slava", "Ann", "Nikita"};
        Scanner input = new Scanner(System.in);
        String contest = input.next();
        int i = 0, cnt = 0, mn, index;
        while(i<contest.length()) {
            mn = contest.length();
            for(String x: names) {
                index = contest.indexOf(x,i);
                if(index!=-1) {
                    mn = Math.min(mn,index+x.length());
                    cnt++;
                }
            }
            i += mn;
        }
        if(cnt==1)
            System.out.println("YES");
        else
            System.out.println("NO");
    }
}