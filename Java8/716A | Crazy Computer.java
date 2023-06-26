import java.util.Scanner;
 
public class Codeforces519A {
    
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int screen = 1, n, c;
        n = input.nextInt();
        c = input.nextInt();
        int[] a = new int[n];
        for(int i=0; i<n; i++) {
            a[i] = input.nextInt();
        }
        for(int i=1; i<n; i++) {
            if(a[i]-a[i-1]>c)
                screen = 1;
            else
                screen++;
        }
        System.out.println(screen);
    }
}