/* *
* all i did here is 
* 1) find the max & min values 
* 2) find how many times max & min were repeated
* the answer then stands (max-min) & (max repeat)*(min repeat) 
* be causious: because we are multiplying large values, longs must be used
* and the case where min == max
* */
 
import java.util.Scanner;
 
public class Codeforces439A {
    
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int b, max = 0, min = 1000000001;
        long Nmx = 0, Nmn = 0;
        while(n>0) {
            b = input.nextInt();
            if(b>max) {
                max = b;
                Nmx = 1;
            }
            else if(b==max) {
                Nmx++;
            }
            if(b<min) {
                min = b;
                Nmn = 1;
            }
            else if(b==min) {
                Nmn++;
            }
            n--;
        }
        long ways = Nmx*Nmn;
        if(min==max)
            ways = (Nmx*(Nmx-1))/2;
        System.out.println((max-min)+" "+ways);
    }
}