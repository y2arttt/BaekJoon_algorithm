import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

class Main {
    static int[] result;
    static int m;
    static void dfs (int i,int n, int r){
        if(r == 0) {
            for(int rs : result){
                System.out.print(rs + " ");
            }
            System.out.println();
            return;
        }

        for(int j = i; j <= n; j++){
            result[m-r] = j;
            dfs(j,n, r -1);

        }

    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int n = sc.nextInt();
        m = sc.nextInt();
        result = new int[m];
        dfs(1,n,m);
    }


}
