import java.util.Scanner;
 
public class Main {
    
    static Scanner in = new Scanner(System.in);
    
    public static void main(String[] args) {
        
        int x = in.nextInt();
        int y = in.nextInt();
        
        if((y>1 || x==0) && x>=(y-1) && (x-y-1)%2==0)
            System.out.println("YES");
        else
            System.out.println("NO");
        
    }
}