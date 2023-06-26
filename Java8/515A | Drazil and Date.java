import java.util.Scanner;
import java.lang.Math.*;
 
public class Main {
 public static void main (String[] args) {
  
  Scanner in = new Scanner(System.in);
  
  int a = in.nextInt();
  int b = in.nextInt();
  int s = in.nextInt();
  
  int minDis = Math.abs(a) + Math.abs(b);
  
  String ans = "Yes";
  
  if(s<minDis || (s-minDis)%2==1) 
      ans = "No";
  
  System.out.println(ans);
  
 }
}