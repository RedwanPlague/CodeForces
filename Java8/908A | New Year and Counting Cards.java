import java.util.Scanner;
 
public class Main {
 public static void main (String[] args) {
  
  Scanner in = new Scanner(System.in);
     
     String s = in.next();
     
     int ans = 0;
     
     for(int i=0; i<s.length(); i++) {
         
         char c = s.charAt(i);
         
         if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
             ans++;
         else if(c=='1' || c=='3' || c=='5' || c=='7' || c=='9')
             ans++;
         
     }
     
     System.out.println(ans);
  
 }
}