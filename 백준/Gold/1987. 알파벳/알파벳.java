import java.util.*;

public class Main {
    static int n, m, max = 0;
    static boolean[] alphabet = new boolean[26];
    static Character[][] map;

    static void dfs(int i, int j, int cnt) {
        if(alphabet[map[i][j] - 'A']) {
            max = Math.max(max, cnt);
            return;
        }

        alphabet[map[i][j] - 'A'] = true;
        cnt++;
        max = Math.max(max, cnt);

        int[][] move = new int[][]{{1,0},{0,1},{-1,0},{0,-1}};
        for(int[] mv : move){
            int x = mv[0] + i;
            int y = mv[1] + j;
            if(0 <= x && x < n && 0 <= y && y < m) {
                dfs(x, y, cnt);
            }
        }
        alphabet[map[i][j] - 'A'] = false;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        sc.nextLine();

        map = new Character[n][m];
        for(int i = 0; i < n; i++) {
            String line = sc.nextLine();
            for(int j = 0; j < m; j++) {
                map[i][j] = line.charAt(j);
            }
        }

        dfs(0, 0, 0);
        System.out.println(max);
    }
}