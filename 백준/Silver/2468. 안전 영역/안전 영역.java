import java.util.*;

public class Main {
    static int[][] map;
    static int n;
    static int result = 1;
    static int cnt;
    static int waterLevel;
    public static void main(String[] args) {
        input();
        solve();
        System.out.println(result);
    }

    private static void input() {
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        map = new int[n][n];
        waterLevel = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                map[i][j] = sc.nextInt();
                waterLevel = Math.max(waterLevel, map[i][j]);
            }
        }
    }

    private static void solve() {
        while (waterLevel > 0) {
            cnt = 0;
            start(waterLevel);
            waterLevel--;
            result = Math.max(result, cnt);
        }
    }

    static Queue<int[]> queue = new LinkedList<>();
    static boolean[][] visited;

    private static void start(int flood) {
        visited = new boolean[n][n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && map[i][j] > flood) {
                    queue.offer(new int[]{i, j});
                    visited[i][j] = true;
                    checkSafeZone(flood);
                }
            }
        }
    }



    private static void checkSafeZone(int flood) {
        int[] dx = {-1, 1, 0, 0};
        int[] dy = {0, 0, -1, 1};

        while (!queue.isEmpty()) {
            int[] curr = queue.poll();
            int x = curr[0];
            int y = curr[1];
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (CheckArrangeNxNy(nx, ny))
                    continue;
                if (map[nx][ny] <= flood)
                    continue;
                visited[nx][ny] = true;
                queue.offer(new int[]{nx, ny});
            }
        }
        cnt++;
    }


    private static boolean CheckArrangeNxNy(int nx, int ny) {
        return nx < 0 || ny < 0 || nx >= n || ny >= n || visited[nx][ny];
    }
}