import java.util.*;

public class Main {
    public static void main(String[] args)  {
        Scanner sc = new Scanner(System.in);
        int l = sc.nextInt();
        int r = sc.nextInt();
        int a = sc.nextInt();

        int diff = Math.abs(l - r);

        int result;
        if(diff > a){
            result = l + r + a - (diff-a);
        } else {
            a = a - (a-diff)%2;
            result = l + r + a;
        }
        System.out.println(result);
    }
}
