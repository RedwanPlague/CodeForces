import java.util.Scanner;
 
public class Main {
    
    int form(char a) {
        return a-'0';
    }
    
 public static void main (String[] args) {
  
  Scanner in = new Scanner(System.in);
  
  String n = in.next();
  StringBuffer ans = new StringBuffer("");
  
  if(n.charAt(0)!='9' && n.charAt(0)>'4')
      ans.append((char)('9'-n.charAt(0)+'0'));
  else
      ans.append(n.charAt(0));
  
  for(int i=1; i<n.length(); i++) {
      
      if(n.charAt(i)>'4')
          ans.append((char)('9'-n.charAt(i)+'0'));
      else
          ans.append(n.charAt(i));
      
  }
  
  System.out.println(ans);
  
 }
}