import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long A = sc.nextLong();
        long B = sc.nextLong();
        long C = sc.nextLong();

        System.out.println(modularExponentiation(A, B, C));
    }

   
    public static long modularExponentiation(long A, long B, long C) {
        long result = 1;

        while (B > 0) {
            if (B % 2 == 1) {
                result = (result * A) % C;
            }
            A = (A * A) % C;
            B /= 2;
        }
        return result;
    }
}