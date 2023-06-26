/* *
* all i did here is 
* find if these two lists have any digit in common
* the answer is then the minimum of the commons
* if they don't then the answer is found using minList1 & minList2
* */
 
import java.util.Scanner;
import java.util.ArrayList;
 
public class Codeforces872A {
    
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int m = input.nextInt();
        int in, min1 = 10, min2 = 10;
        ArrayList<Integer> list1 = new ArrayList<Integer>();
        ArrayList<Integer> list2 = new ArrayList<Integer>();
        while(n>0) {
            in = input.nextInt();
            list1.add(in);
            if(in<min1)
                min1 = in;
            n--;
        }
        while(m>0) {
            in = input.nextInt();
            list2.add(in);
            if(in<min2)
                min2 = in;
            m--;
        }
        int ans = 10;
        for(int x: list1) {
            if(list2.contains(x) && x<ans) {
                ans = x;
            }
        }
        if(ans==10) {
            if(min1>min2)
                min1 += min2 - (min2 = min1);
            ans = 10*min1+min2;
        }
        System.out.println(ans);
    }
}