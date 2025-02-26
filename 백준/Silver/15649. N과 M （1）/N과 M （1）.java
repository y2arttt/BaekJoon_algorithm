import java.util.Scanner;



class Main {

    static int n;
    static int m;
    static boolean[] check;
    static int[] result;
    static void dfs(int k){
        if(k == m){
            for(int i : result){
                System.out.print(i+" ");
            }
            System.out.println();
            return;
        }

        for(int i=1; i<=n; i++){
            if(!check[i]){
                check[i] = true;
                result[k] = i;
                dfs(k + 1);
                check[i] = false;
            }
        }


    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        check = new boolean[n+1];
        result = new int[m];

        for (int i = 0; i < n; i++) {
            check[i] = false;
        }
        dfs(0);



    }
}