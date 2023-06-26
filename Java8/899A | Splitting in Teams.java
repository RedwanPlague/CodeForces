import java.util.Scanner;
 
public class Main {
 public static void main (String[] args) {
  
  Scanner in = new Scanner(System.in);
  
  int n = in.nextInt();
  int one = 0, two = 0;
  int a;
  
  for(int i=0; i<n; i++) {
      a = in.nextInt();
      if(a==1)
          one++;
      else
          two++;
  }
  
  int ans = 0;
  
  if(two>one) {
      ans = one;
  }
  else {
      ans = two;
      one -= two;
      ans += one/3;
  }
  
  System.out.println(ans);
  
 }
}