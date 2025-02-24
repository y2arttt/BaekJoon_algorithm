import java.io.*;

class Main {
    static int[][] arr;
    static long[][] visit;
    static int n;

    static long dfs(int i, int j) {
        if (i >= n || j >= n) return 0;
        if (i == n - 1 && j == n - 1) return 1;

        if (visit[i][j] != -1) return visit[i][j];

        visit[i][j] = 0;
        int jump = arr[i][j];

        if (jump == 0) return 0;

        if (i + jump < n) {  // 아래로 jump만큼
            visit[i][j] += dfs(i + jump, j);
        }
        
        if (j + jump < n) {  // 오른쪽으로 jump만큼
            visit[i][j] += dfs(i, j + jump);
        }

        return visit[i][j];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());
        arr = new int[n][n];
        visit = new long[n][n];

        // visit 배열을 -1로 초기화
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                visit[i][j] = -1;
            }
        }

        for (int i = 0; i < n; i++) {
            String[] line = br.readLine().split(" ");
            for (int j = 0; j < n; j++) {
                arr[i][j] = Integer.parseInt(line[j]);
            }
        }

        System.out.println(dfs(0, 0));
        br.close();
    }
}