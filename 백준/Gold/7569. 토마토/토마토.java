import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);


        final int[][] diff = {{0,0,1}, {0,0,-1}, {0,1,0}, {0,-1,0}, {1,0,0}, {-1,0,0}};
        Queue<int[]> q = new LinkedList<>();

        int m = sc.nextInt();
        int n = sc.nextInt();
        int h = sc.nextInt();
        int cnt = 0;
        int[][][] box = new int[h][n][m];
        boolean[][][] visited = new boolean[h][n][m];

        for(int i = 0; i < h; i++){
            for(int j = 0; j < n; j++){
                for(int k = 0; k < m; k++){
                    box[i][j][k] = sc.nextInt();
                    if(box[i][j][k] == 1){
                        q.add(new int[]{i, j, k});
                        visited[i][j][k] = true;
                    }else if(box[i][j][k] == 0){
                        cnt++;
                    }
                }
            }
        }

        int day = 0;

        while(!q.isEmpty() && cnt > 0){
            int size = q.size();

            for(int s = 0; s < size; s++){
                int[] cur = q.poll();
                int z = cur[0];
                int x = cur[1];
                int y = cur[2];

                for(int[] mv : diff){
                    int nz = z + mv[0];
                    int nx = x + mv[1];
                    int ny = y + mv[2];


                    if(nz < 0 || nz >= h || nx < 0 || nx >= n || ny < 0 || ny >= m)
                        continue;


                    if(visited[nz][nx][ny] || box[nz][nx][ny] == -1)
                        continue;


                    if(box[nz][nx][ny] == 0){
                        box[nz][nx][ny] = 1;
                        cnt--;
                        visited[nz][nx][ny] = true;
                        q.add(new int[]{nz, nx, ny});
                    }
                }
            }

            day++;
        }


        if(cnt == 0){
            System.out.println(day);
        }else{
            System.out.println(-1);
        }
    }
}