import java.util.*;

import static java.lang.Math.abs;

class Main {

    static int n;
    static int[][] stat;
    static boolean member[];
    static int min = Integer.MAX_VALUE;

    static void dfs(int idx, int c) {
        if(c == n/2){
            stat();
        }
        for(int i = idx; i<=n; i++){
            if(!member[i]){
                member[i] = true;
                dfs(i+1,c+1);
                member[i] = false;
            }
        }
    }
    static void stat(){
        int start = 0;
        int link = 0;
        for(int i = 1; i<n; i++){
            for(int j = i+1; j<=n; j++){
                if(member[i]&&member[j]){
                    start += stat[i][j] + stat[j][i];
                }
                else if((!member[i]) && (!member[j])){
                    link += stat[i][j] + stat[j][i];
                }
            }
        }
        min = Math.min(min, abs(start-link));
        if(min == 0){
            System.out.println(0);
            System.exit(0);
        }
    }


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        stat = new int[n+1][n+1];
        member = new boolean[n+1];
        for (int i = 1; i < n+1; i++) {
            for (int j = 1; j < n+1; j++) {
                stat[i][j] = sc.nextInt();
            }
        }
        dfs(1,0);

        System.out.println(min);
    }
}
