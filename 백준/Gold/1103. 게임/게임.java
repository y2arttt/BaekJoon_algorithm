import java.util.*;

public class Main {
    static int n, m;
    static String[] map;
    static int[][] dp;
    static boolean[][] visited;   // 메모이제이션 확인용
    static boolean[][] onPath;    // ***현재 DFS 경로 체크용 경로 체크해서 무한루프 확인해야됐음..
    static boolean infinite = false;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        sc.nextLine();

        map = new String[n];
        for (int i = 0; i < n; i++) {
            map[i] = sc.nextLine();
        }

        dp = new int[n][m];
        visited = new boolean[n][m];
        onPath = new boolean[n][m];

        int result = dfs(0, 0);

        if (infinite) {
            System.out.println(-1);
        } else {
            System.out.println(result);
        }
    }

    static int dfs(int i, int j) {
        if (i < 0 || i >= n || j < 0 || j >= m || map[i].charAt(j) == 'H') {
            return 0; // 보드 밖이거나 구멍(H)이면 이동 불가
        }

        if (onPath[i][j]) {
            // 현재 경로에서 다시 방문 → 무한 루프
            infinite = true;
            return 0;
        }

        if (visited[i][j]) {
            return dp[i][j]; // 이미 계산한 값 있으면 재사용
        }

        onPath[i][j] = true;
        visited[i][j] = true;

        int next = map[i].charAt(j) - '0'; // 현재 칸에서 이동할 칸 수
        int maxMove = 0;

        int[] di = {-1, 1, 0, 0};
        int[] dj = {0, 0, -1, 1};

        for (int k = 0; k < 4; k++) {
            int ni = i + di[k] * next;
            int nj = j + dj[k] * next;
            maxMove = Math.max(maxMove, dfs(ni, nj));
        }

        dp[i][j] = maxMove + 1;
        onPath[i][j] = false; // 경로 복귀 시 해제
        return dp[i][j];
    }
}
