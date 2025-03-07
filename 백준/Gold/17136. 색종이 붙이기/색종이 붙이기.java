import java.util.*;

public class Main {
    static int[][] map = new int[10][10];
    static int n = 0;
    static int max = Integer.MAX_VALUE; 
    static int[] paper = new int[]{0, 5, 5, 5, 5, 5}; 
    static ArrayList<int[]> list = new ArrayList<>();

    static void dfs(int m, int cnt) {
        if(m == n) {
            max = Math.min(max, cnt);
            return;
        }
        
        if(cnt >= max) {
            return;
        }
        
        int i = -1, j = -1;
        outer:
        for(i = 0; i < 10; i++) {
            for(j = 0; j < 10; j++) {
                if(map[i][j] == 1) {
                    break outer;
                }
            }
        }
        
        if(i == 10) return;

        
        for(int k = 1; k <= 5; k++) {
            if(paper[k] > 0 && canCover(i, j, k)) {
                paper[k]--; 
                cover(i, j, k, 0);
                dfs(m + k*k, cnt + 1);
                cover(i, j, k, 1); 
                paper[k]++;
            }
        }
    }

    
    static boolean canCover(int i, int j, int k) {
        if(i + k > 10 || j + k > 10) return false;

        for(int x = i; x < i + k; x++) {
            for(int y = j; y < j + k; y++) {
                if(map[x][y] != 1) return false;
            }
        }
        return true;
    }

    
    static void cover(int i, int j, int k, int value) {
        for(int x = i; x < i + k; x++) {
            for(int y = j; y < j + k; y++) {
                map[x][y] = value;
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                map[i][j] = sc.nextInt();
                if (map[i][j] == 1) {
                    n++;
                }
            }
        }

        dfs(0, 0);
        if (max == Integer.MAX_VALUE) {
            System.out.println(-1);
        } else {
            System.out.println(max);
        }
    }
}