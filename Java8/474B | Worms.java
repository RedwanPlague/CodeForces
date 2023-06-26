import java.util.Scanner;
 
public class Codeforces474B {
 public static void main (String[] args) throws java.lang.Exception {
     Scanner input = new Scanner(System.in);
  int n = input.nextInt();
  int[] ar = new int[n];
  for(int i=0; i<n; i++)
      ar[i] = input.nextInt();
  for(int i=1; i<n; i++)
      ar[i] += ar[i-1];
  int q = input.nextInt();
  int in;
  for(int i=0; i<q; i++) {
      in = input.nextInt();
      int lo = 0, hi = n-1, mid;
      while(lo<hi-1) {
          mid = (lo+hi)/2;
          if(ar[mid]>=in)
              hi = mid;
          else
              lo = mid+1;
      }
      if(in<=ar[hi] && in>ar[lo])
          System.out.println(hi+1);
      else
          System.out.println(lo+1);
  }
 }
}