import java.util.Scanner;
 
public class Main {
    
    public static boolean special(int d) {
        if(d == 28 || d == 29)
            return true;
        return false;
    }
    
 public static void main (String[] args) {
  
  Scanner in = new Scanner(System.in);
  
  int n = in.nextInt();
  int[] days = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
  int[] ar = new int[n];
  
  for(int i=0; i<n; i++) {
      ar[i] = in.nextInt();
  }
  
  boolean ans = false;
  boolean spec = false;
  
  for(int i=0; i<12; i++) {
      
      boolean temp = true;
      
      for(int j=0; j<n; j++) {
          if( special(days[(i+j)%12]) && special(ar[j]) ) {
              if(ar[j]==29) {
                  if(!spec)
                      spec = true;
                  else
                      temp = false;
              }
          }
          else if( days[(i+j)%12] != ar[j] )
              temp = false;
      }
      
      if(temp == true) {
          ans = true;
          break;
      }
      
  }
  
  if(ans)
      System.out.println("Yes");
  else
      System.out.println("No");
  
 }
}