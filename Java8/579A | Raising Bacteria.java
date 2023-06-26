import java.util.Scanner;
public class Codeforces579A {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int bact = 0;
        while(n>0)
        {
            if(n%2==1)
            {
                n--;
                bact++;
            }
            else
                n /= 2;
        }
        System.out.println(bact);
    }
}