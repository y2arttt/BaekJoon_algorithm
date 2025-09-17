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

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                w[i][j] = sc.nextInt();
            }
        }

        dp = new int[1<<n][n];
        for (int i = 0; i < (1 << n); i++) {
            Arrays.fill(dp[i], -1);
        }

        int ans = dfs(0, 1); // 출발 도시 0, 방문 집합 1
        System.out.println(ans);
    }

    static int dfs(int now, int visit) {
        if (visit == (1 << n) - 1) { // 모든 도시 방문
            if (w[now][0] == 0) return INF; // 돌아갈 길 없으면 INF
            return w[now][0];               // 출발지로 돌아가는 비용
        }

        if (dp[visit][now] != -1) return dp[visit][now];

        int ret = INF;
        for (int i = 0; i < n; i++) {
            if ((visit & (1 << i)) != 0) continue; // 이미 방문
            if (w[now][i] == 0) continue;         // 길 없음

            int newVisit = visit | (1 << i);
            int cost = dfs(i, newVisit) + w[now][i]; // now에서 i~~로 가는데 필요한 최소 비용
            ret = Math.min(ret, cost);
        }

        return dp[visit][now] = ret;
    }
}
