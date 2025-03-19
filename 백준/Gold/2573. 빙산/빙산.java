import java.util.*;

public class Main {
    static int N, M;
    static int[][] map;
    static int[][] meltCount;
    static boolean[][] visited;
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};
    static int iceCount = 0;

    public static void main(String[] args) {
        input();
        int year = 0;
        solve(year);
    }
    private static void input() {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();

        map = new int[N][M];

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                map[i][j] = sc.nextInt();
                if (map[i][j] > 0) {
                    iceCount++;
                }
            }
        }
    }
    
    private static void solve(int year) {
        while (true) {
            int currIcebergCount = countIcebergs();

            if (currIcebergCount >= 2) {
                System.out.println(year);
                break;
            }

            if (currIcebergCount == 0) {
                System.out.println(0);
                break;
            }

            melt();
            year++;
        }
    }

    

    static int countIcebergs() {
        int count = 0;
        visited = new boolean[N][M];

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (map[i][j] > 0 && !visited[i][j]) {
                    dfs(i, j);
                    count++;
                }
            }
        }

        return count;
    }

    static void dfs(int x, int y) {
        visited[x][y] = true;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M && map[nx][ny] > 0 && !visited[nx][ny]) {
                dfs(nx, ny);
            }
        }
    }

    static void melt() {
        meltCount = new int[N][M];

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (map[i][j] > 0) {
                    for (int k = 0; k < 4; k++) {
                        int nx = i + dx[k];
                        int ny = j + dy[k];

                        if (nx >= 0 && nx < N && ny >= 0 && ny < M && map[nx][ny] == 0) {
                            meltCount[i][j]++;
                        }
                    }
                }
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (map[i][j] > 0) {
                    map[i][j] = Math.max(0, map[i][j] - meltCount[i][j]);
                    if (map[i][j] == 0) {
                        iceCount--;
                    }
                }
            }
        }
    }
}