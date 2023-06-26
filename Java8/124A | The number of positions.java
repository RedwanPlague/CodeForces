import java.util.Scanner;
import java.lang.Math.*;
 
public class Main {
 public static void main (String[] args) {
  
  Scanner in = new Scanner(System.in);
  
  int n = in.nextInt();
  int a = in.nextInt();
  int b = in.nextInt();
  
  System.out.println(n - Math.max(a,n-b-1));
  
 }
}