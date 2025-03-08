import java.util.*;

public class Main {
    static int[][] map;
    static int n, m;
    static int[] di = {-1, 0, 1, 0};
    static int[] dj = {0, 1, 0, -1};

    static void solve(int ri, int rj, int dir){
        while (true){
            map[ri][rj] = -1;
            boolean checked = false;
            int originalDir = dir;
            for(int i=0; i<4; i++){
                if (0<= ri + di[i] && ri + di[i]<n && 0<= rj + dj[i] && rj + dj[i]<m){
                    if(map[ri + di[i]][rj + dj[i]] == 0){
                        checked = true;
                    }
                }
            }
            if(checked){
                dir = (dir+3)%4;
                if (0<= ri+di[dir] && ri+di[dir] < n && 0 <= rj+dj[dir] && rj+dj[dir] < m && map[ri+di[dir]][rj+dj[dir]] == 0){
                    ri = ri+di[dir];
                    rj = rj+dj[dir];
                }
            }else {
                // 방향전환이 핵심이었음!!!!!
//                int tdir = (dir+2)%4;
//                int ti = ri + di[tdir];
//                int tj = rj + dj[tdir];
                int ti = ri - di[dir];
                int tj = rj - dj[dir];
                if(0<= ti && ti < n && 0<= tj && tj < m && map[ti][tj] != 1){
                    ri = ti;
                    rj = tj;
                }
                else {
                    break;
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        map = new int[n][m];
        int ri, rj,dir;

        ri = sc.nextInt();
        rj = sc.nextInt();
        dir = sc.nextInt();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                map[i][j] = sc.nextInt();
            }
        }
        solve(ri, rj, dir);
        int cnt=0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(map[i][j] == -1){
                    cnt++;
                }
            }
        }
        System.out.println(cnt);

    }
}