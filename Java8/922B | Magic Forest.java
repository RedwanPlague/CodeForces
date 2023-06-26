import java.util.Scanner;
 
public class Main {
    
    static Scanner in = new Scanner(System.in);
    
    static boolean isTriangle(int a, int b, int c) {
        return ( (a+b>c) && (b+c>a) && (c+a>b) );
    }
    
    public static void main(String[] args) {
        
        int n = in.nextInt();
        int cnt = 0;
        
        for(int i=1; i<=n; i++) {
            for(int j=i; j<=n; j++) {
                if( isTriangle(i^j,i,j) && ((i^j)>=j) && ((i^j)<=n) )
                    cnt++;
            }
        }
        
        System.out.println(cnt);
        
    }
}