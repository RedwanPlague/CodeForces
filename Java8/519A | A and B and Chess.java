import java.util.Scanner;
 
public class Codeforces519A {
    
    static char[] ar = { 'Q', 'R', 'B', 'N', 'P', 'K' };
    static int[] w = { 9, 5, 3, 3, 1, 0 };
    
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int white = 0, black = 0;
        char piece;
        String in;
        for(int r=0; r<8; r++) {
            in = input.next();
            for(int c=0; c<8; c++) {
                piece = in.charAt(c);
                if(piece>='A' && piece<='Z')
                    white += weight(piece);
                else if(piece>='a' && piece<='z')
                    black += weight((char)(piece-'a'+'A'));
            }
        }
        if(white>black)
            System.out.println("White");
        else if(black>white)
            System.out.println("Black");
        else
            System.out.println("Draw");
    }
    public static int weight(char in) {
        for(int i=0; i<ar.length; i++) {
            if(ar[i]==in)
                return w[i];
        }
        return 0;
    }
}