import java.util.*;

public class Main {

    static final int INF =1_000_000_000;
    static int n;
    static int[][] w;
    static int[][] dp;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        w = new int[n][n];
        dp = new int[n][1<<n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                w[i][j] = sc.nextInt();
            }
        }

        for (int i = 0; i < n; i++) {
            Arrays.fill(dp[i], -1);
        }

        int ans = dfs(0,1); // 출발 도시 0, 방문 집합 1
        System.out.println(ans);
    }

    static int dfs(int now, int visited) {
        if (visited == (1<<n)-1) {
            if (w[now][0]==0) return INF;
            else return w[now][0];
        }

        if (dp[now][visited] != -1) return dp[now][visited];

        int res = INF;
        for (int i = 0; i < n; i++) {
            if ((visited & 1<<i) != 0) continue;
            if (w[now][i] == 0) continue;

            int newVisit = visited | (1<<i);
            int cost = dfs(i,newVisit) + w[now][i];
            res = Math.min(res, cost);
        }

        return dp[now][visited] = res;
    }


}
