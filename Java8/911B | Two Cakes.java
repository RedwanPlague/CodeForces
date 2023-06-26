import java.util.Scanner;
 
public class Main {
 public static void main (String[] args) {
  
  Scanner in = new Scanner(System.in);
  
  int n = in.nextInt();
  int a = in.nextInt();
  int b = in.nextInt();
  
  int ans = 0;
  
  for(int i=1; i<n; i++) {
      
      ans = Math.max(ans, Math.min(a/i, b/(n-i)));
      
  }
  
  System.out.println(ans);
  
 }
}