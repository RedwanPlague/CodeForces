import java.util.Scanner;
 
public class Codeforces439A {
    
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int d = input.nextInt();
        int a, S = 0;
        for(int i=0; i<n; i++) {
            a = input.nextInt();
            S += a;
        }
        if((d-S)/10<(n-1) || (d-S)<0)
            System.out.println("-1");
        else
            System.out.println((d-S)/5);
    }
}