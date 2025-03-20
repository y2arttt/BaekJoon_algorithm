import java.util.*;

public class Main {
    static int k, w, h;
    static int[][] map;
    static int[][][] dist;
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};
    static int[] hdx = {-2, -1, 1, 2, 2, 1, -1, -2};
    static int[] hdy = {-1, -2, -2, -1, 1, 2, 2, 1};

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        k = sc.nextInt();
        w = sc.nextInt();
        h = sc.nextInt();

        map = new int[h][w];
        dist = new int[h][w][k+1];

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                map[i][j] = sc.nextInt();
                Arrays.fill(dist[i][j], Integer.MAX_VALUE);
            }
        }

        Queue<int[]> q = new LinkedList<>();
        dist[0][0][0] = 0;
        q.add(new int[]{0, 0, 0});

        while (!q.isEmpty()) {
            int[] cur = q.poll();
            int x = cur[0];
            int y = cur[1];
            int curK = cur[2];

            if (x == h-1 && y == w-1) {
                System.out.println(dist[x][y][curK]);
                return;
            }

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (isRangeCheck(nx, ny, curK, x, y, curK)) continue;

                dist[nx][ny][curK] = dist[x][y][curK] + 1;
                q.add(new int[]{nx, ny, curK});
            }

            if (curK < k) {
                for (int i = 0; i < 8; i++) {
                    int nx = x + hdx[i];
                    int ny = y + hdy[i];

                    if (isRangeCheck(nx, ny, curK + 1, x, y, curK)) continue;

                    dist[nx][ny][curK + 1] = dist[x][y][curK] + 1;
                    q.add(new int[]{nx, ny, curK + 1});
                }
            }
        }

        System.out.println(-1);
    }

    private static boolean isRangeCheck(int nx, int ny, int nextK, int x, int y, int curK) {
        if (nx < 0 || ny < 0 || nx >= h || ny >= w) return true;
        if (map[nx][ny] == 1) return true;
        if (dist[nx][ny][nextK] <= dist[x][y][curK] + 1) return true;
        return false;
    }
}