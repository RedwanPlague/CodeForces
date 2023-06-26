import java.util.Scanner;
public class Codeforces448A {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int a = input.nextInt();
        a += input.nextInt();
        a += input.nextInt();
        int b = input.nextInt();
        b += input.nextInt();
        b += input.nextInt();
        int n = input.nextInt();
        int selves = (int)Math.ceil((double)a/5.0);
        selves += (int)Math.ceil((double)b/10.0);
        if(selves>n)
            System.out.println("NO");
        else
            System.out.println("YES");
    }
}