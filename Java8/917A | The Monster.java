import java.util.Scanner;
 
public class Main {
 public static void main (String[] args) {
  
  Scanner in = new Scanner(System.in);
  
  String s = in.next();
  int cur;
  boolean valid;
  boolean[][] f = new boolean[s.length()][s.length()];
  boolean[][] g = new boolean[s.length()][s.length()];
  
  for(int l=0; l<s.length(); l++) {
      
      valid = true;
      cur = 0;
      
      for(int r=l; r<s.length(); r++) {
          if(s.charAt(r) == ')')
              cur--;
          else
              cur++;
          if(cur < 0)
              valid = false;
          f[l][r] = valid;
      }
  }
  
  for(int r=s.length()-1; r>=0; r--) {
      
      valid = true;
      cur = 0;
      
      for(int l=r; l>=0; l--) {
          if(s.charAt(l) == '(')
              cur--;
          else
              cur++;
          if(cur < 0)
              valid = false;
          g[l][r] = valid;
      }
  }
  
  int cnt = 0;
  
  for(int l=0; l<s.length(); l++) {
      for(int r=l; r<s.length(); r++) {
          if(f[l][r] && g[l][r] && (r-l+1)%2==0) {
              cnt++;
              //System.out.println(l + " " + r);
          }
      }
  }
  
  System.out.println(cnt);
  
 }
}