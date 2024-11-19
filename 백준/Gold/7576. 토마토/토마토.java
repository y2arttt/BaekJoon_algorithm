import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int m = sc.nextInt();
        int n = sc.nextInt();

        int[][] arr = new int[n][m];
        int max = 1;
        int cnt = 0;

        Queue<int[]> dq = new LinkedList<>();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                arr[i][j] = sc.nextInt();
                if (arr[i][j] == 1) {
                    dq.offer(new int[]{i, j});
                }
                if (arr[i][j] == -1) {
                    cnt++;
                }
            }
        }

        int[][] move = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        while (!dq.isEmpty()) {
            int[] tmp = dq.poll();
            cnt++;

            for (int[] mv : move) {
                int nx = tmp[0] + mv[0];
                int ny = tmp[1] + mv[1];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m && arr[nx][ny] == 0) {
                    arr[nx][ny] = arr[tmp[0]][tmp[1]] + 1;
                    dq.offer(new int[]{nx, ny});
                    max = Math.max(max, arr[nx][ny]);
                }
            }
        }

        if (n * m - cnt == 0) {
            System.out.println(max - 1);
        } else {
            System.out.println(-1);
        }

        sc.close();
    }
}