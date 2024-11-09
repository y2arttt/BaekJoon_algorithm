import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] dp = new int[n+1];
        Arrays.fill(dp, 106);
        dp[1] = 0;
        for (int i = 2; i <= n; i++) {
            int t1 = 106, t2 = 106, t3 = 106;
            if(i%3==0) t1 = dp[i/3]+1;
            if(i%2==0) t2 = dp[i/2]+1;
            t3 = dp[i-1]+1;
            dp[i] = Math.min(t1, Math.min(t2, t3));
        }
        System.out.println(dp[n]);
    }
}
