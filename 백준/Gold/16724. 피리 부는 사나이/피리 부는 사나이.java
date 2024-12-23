import java.util.*;

public class Main {
    static int n, m;
    static int answer = 0;

    static boolean dfs(char[][] map, int[][] check, int i, int j, int idx) {
        if(check[i][j] != -1) {
            return check[i][j] == idx;
        }

        check[i][j] = idx;
        int[][] move = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        char[] mvc = {'U','D','L','R'};

        for(int k = 0; k < 4; k++) {
            int ni = i + move[k][0];
            int nj = j + move[k][1];
            if(map[i][j] == mvc[k] && 0 <= ni && ni < n && 0 <= nj && nj < m) {
                if(dfs(map, check, ni, nj, idx)) {
                    return true;
                }
            }
        }
        return false;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        sc.nextLine();

        char[][] map = new char[n][m];
        int[][] check = new int[n][m];
        for(int i = 0; i < n; i++) {
            String line = sc.nextLine();
            for(int j = 0; j < m; j++) {
                map[i][j] = line.charAt(j);
                check[i][j] = -1;
            }
        }

        int idx = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(check[i][j] == -1) { 
                    if(dfs(map, check, i, j, idx)) {
                        answer++;
                    }
                    idx++;
                }
            }
        }
        System.out.println(answer);
    }
}