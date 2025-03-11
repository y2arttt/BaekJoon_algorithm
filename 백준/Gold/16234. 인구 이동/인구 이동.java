import java.util.*;

public class Main {
    static int[][] map;
    static boolean[][] visited;
    static int n,L,R;

    static boolean nations() {
        visited = new boolean[n][n];
        boolean flag = false;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    if(bfs(i, j)){
                        flag = true;
                    }
                }
            }
        }
        return flag;
    }

    static boolean bfs(int i, int j) {
        int[] dx = {-1, 0, 1, 0};
        int[] dy = {0, 1, 0, -1};

        List<int[]> association = new ArrayList<>();
        Queue<int[]> q = new LinkedList<>();

        q.add(new int[]{i, j});
        visited[i][j] = true;
        association.add(new int[]{i, j});

        int totalPopulation = map[i][j];

        while (!q.isEmpty()) {
            int[] pos = q.poll();
            int x = pos[0];
            int y = pos[1];

            for (int k = 0; k < 4; k++) {
                int nextX = x + dx[k];
                int nextY = y + dy[k];

                if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= n) continue;
                if (visited[nextX][nextY]) continue;

                int scope = Math.abs(map[x][y] - map[nextX][nextY]);
                if (L <= scope && scope <= R) {
                    visited[nextX][nextY] = true;
                    q.add(new int[]{nextX, nextY});
                    association.add(new int[]{nextX, nextY});
                    totalPopulation += map[nextX][nextY];
                }
            }
        }

        if (association.size() > 1) {
            int newPopulation = totalPopulation / association.size();
            for (int[] pos : association) {
                map[pos[0]][pos[1]] = newPopulation;
            }
            return true;
        }

        return false;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        L = sc.nextInt();
        R = sc.nextInt();
        map = new int[n][n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                map[i][j] = sc.nextInt();
            }
        }

        int day = 0;
        while (nations()) {
            day++;
        }

        System.out.println(day);
    }
}