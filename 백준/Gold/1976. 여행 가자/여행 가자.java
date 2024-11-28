import java.util.*;

public class Main {

    public static int find(int[] p,int i){
        if(i != p[i]){
            p[i] = find(p,p[p[i]]);

        }
        return p[i];

    }
    public static void union(int[] p,int i,int j){
        int rootI = find(p,i);
        int rootJ = find(p,j);
        if(rootI == rootJ){
            return;
        }
        else if(rootI < rootJ){
            p[rootJ] = rootI;
        }
        else {
            p[rootI] = p[rootJ];
        }
    }

    public static void main(String[] args) {
            Scanner sc = new Scanner(System.in);

            int n = sc.nextInt();
            int m = sc.nextInt();
            int[][] arr = new int[n+1][n+1];
            int[] p = new int[n+1];
            int[] plan = new int[m];
            for(int i = 1; i <= n; i++){
                p[i] = i;
            }
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    arr[i][j] = sc.nextInt();
                }
            }
            for(int i = 0; i < m; i++){
                plan[i] = sc.nextInt();
            }
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if(arr[i][j] == 1){
                        union(p,i,j);
                    }
                }
            }
            int s = p[plan[0]];
            boolean flag = false;
            for(int pl : plan){
                if(p[pl] != s){
                    flag = true;
                    break;
                }
            }
/*            for(int pp : p){
                System.out.print(pp+" ");
            }*/
            if(flag){
                System.out.println("NO");
            }
            else {
                System.out.println("YES");
            }
    }
}