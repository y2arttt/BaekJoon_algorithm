import java.util.*;

public class Main {
    static int n;
    static ArrayList<Integer>[] graph;
    static int[][] dp;
    static boolean[] visited;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();

        graph = new ArrayList[n + 1];
        for (int i = 1; i <= n; i++) graph[i] = new ArrayList<>();

        for (int i = 0; i < n - 1; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            graph[u].add(v);
            graph[v].add(u);
        }

        dp = new int[n + 1][2];
        visited = new boolean[n + 1];

        dfs(1);

        System.out.println(Math.min(dp[1][0], dp[1][1]));
    }

    static void dfs(int now) {
        visited[now] = true;
        dp[now][0] = 1;

        for (int next : graph[now]) {
            if (!visited[next]) {
                dfs(next);
                dp[now][0] += Math.min(dp[next][0], dp[next][1]);
                dp[now][1] += dp[next][0];
            }
        }
    }
}
