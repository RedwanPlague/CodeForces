import java.util.Scanner;
public class Codeforces599A {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int a = input.nextInt();
        int b = input.nextInt();
        int c = input.nextInt();
        int min = a+b+c;
        min = Math.min(min,2*(a+b));
        min = Math.min(min,2*(b+c));
        min = Math.min(min,2*(c+a));
        System.out.println(min);
    }
}