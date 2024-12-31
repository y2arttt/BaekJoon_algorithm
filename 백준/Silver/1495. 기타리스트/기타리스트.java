import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int s = sc.nextInt();
        int m = sc.nextInt();

        int[] v = new int[n+1];
        boolean[][] dp = new boolean[n+1][m+1]; 

        for(int i = 1; i <= n; i++) {
            v[i] = sc.nextInt();
        }

        dp[0][s] = true;

        for(int i = 1; i <= n; i++) {

            for(int j = 0; j <= m; j++) {
                if(!dp[i-1][j]) continue;
                
                if(j + v[i] <= m) {
                    dp[i][j + v[i]] = true;
                }
                if(j - v[i] >= 0) {
                    dp[i][j - v[i]] = true;
                }
            }
        }
        
        int result = -1;
        for(int i = m; i >= 0; i--) {
            if(dp[n][i]) {
                result = i;
                break;
            }
        }

        System.out.println(result);
    }
}