import java.util.Scanner;
 
public class Main {
    
    static Scanner in = new Scanner(System.in);
    
    static long gcd(long a, long b) {
        if(a%b == 0)
            return b;
        return gcd(b, a%b);
    }
    
    static long lcm(long a, long b) {
        return (a/gcd(a,b)*b);
    }
    
    public static void main(String[] args) {
        
        long n = in.nextLong();
        long k = in.nextLong();
        
        long keep = 1;
        
        for(int i=1; i<=k; i++) {
            keep = lcm(keep, i);
            if(keep > n+1) {
                System.out.println("No");
                return;
            }
        }
        
        if((n+1)%keep == 0) {
            System.out.println("Yes");
        }
        else {
            System.out.println("No");
        }
        
    }
}