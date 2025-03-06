import java.util.*;
import static java.lang.Math.abs;

class Main {
    static int n, m, c, h;
    static int[][] distance;
    static int[][] house;
    static int[][] chicken;
    static boolean[] selected; 
    static int min_d = Integer.MAX_VALUE;

    static void dfs(int idx, int count) {
        if (count == m) {
            check();
            return;
        }

        for (int i = idx; i < c; i++) {
            if (!selected[i]) {
                selected[i] = true;
                dfs(i + 1, count + 1);
                selected[i] = false;
            }
        }
    }

    static void check() {
        int total_distance = 0;
        for (int i = 0; i < h; i++) {
            int min_distance = Integer.MAX_VALUE;
            for (int j = 0; j < c; j++) {
                if (selected[j]) {
                    min_distance = Math.min(min_distance, distance[i][j]);
                }
            }
            total_distance += min_distance;
        }
        min_d = Math.min(min_d, total_distance);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();

        house = new int[2*n][2];
        chicken = new int[13][2];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int tmp = sc.nextInt();
                if (tmp == 1) {
                    house[h][0] = i;
                    house[h][1] = j;
                    h++;
                }
                if (tmp == 2) {
                    chicken[c][0] = i;
                    chicken[c][1] = j;
                    c++;
                }
            }
        }

        distance = new int[h][c];
        selected = new boolean[c];

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < c; j++) {
                distance[i][j] = abs(house[i][0] - chicken[j][0]) + abs(house[i][1] - chicken[j][1]);
            }
        }

        dfs(0, 0);
        System.out.println(min_d);
    }
}