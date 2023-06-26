import java.util.Scanner;
 
public class Main {
    
    public static int increase(int a) {
        
        if(a==2)
            return 2;
        if(a%4==0)
            return 3;
        return 1;
        
    }
    
 public static void main (String[] args) {
  
  Scanner in = new Scanner(System.in);
  
  int n = in.nextInt();
  
  if( (n&1) == 0 ) {
      
      if( ((n/2)&1) == 0 ) {
          
          System.out.print("0\n" + n/2);
          
          for(int i=1; i<n/2; i+=2) {
              System.out.print(" " + i + " " + (n-i+1));
          }
          
      }
      
      else {
          
          System.out.print("1\n" + n/2);
          
          for(int i=1; i<n/2; i+=2) {
              System.out.print(" " + i + " " + (n-i+1));
          }
          
          System.out.println(" " + n/2);
          
      }
      
  }
  
  else {
      
      if( (n+1)%4 == 0 )
          System.out.println(0);
      else
          System.out.println(1);
      
      System.out.print((n+1)/2);
      
      for(int i=1; i<=n; i+=increase(i)) {
          System.out.print(" " + i);
      }
      
  }
  
 }
}