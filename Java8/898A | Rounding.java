import java.util.Scanner;
 
public class Main {
 public static void main (String[] args) {
  
  Scanner in = new Scanner(System.in);
  
  int n = in.nextInt();
  
  int floor = 10*(n/10);
  int ceil = floor + 10;
  
  int ans = ( (n-floor)<(ceil-n) ) ? floor : ceil ;
  
  System.out.println(ans);
  
 }
}