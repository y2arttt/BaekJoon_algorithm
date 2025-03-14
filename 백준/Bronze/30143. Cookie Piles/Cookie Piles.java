import java.util.*;

public class Main {
    public static void main(String[] args)  {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int i = 0; i < t; i++) {
            int n = sc.nextInt();
            int a = sc.nextInt();
            int d = sc.nextInt();
            int result = (n*(2*a+(n-1)*d))/2;
            System.out.println(result);
        }
    }
}