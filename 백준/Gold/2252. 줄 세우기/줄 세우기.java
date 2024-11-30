import java.util.*;

public class Main {

    public static boolean[] visit;
    public static Vector<Integer>[] v;
    public static void check(int n){
        if(!visit[n]){
            visit[n] = true;
            for(int i : v[n]){
                if(!visit[i]){
                    check(i);
                }
            }
            System.out.print(n+" ");
        }
    }

    public static void main(String[] args) {
            Scanner sc = new Scanner(System.in);

            int n = sc.nextInt();
            visit = new boolean[n+1];
            v = new Vector[n+1];
            for (int i = 0; i <= n; i++) {
                v[i] = new Vector<>();
            }
            int m = sc.nextInt();
            for (int i = 0; i < m; i++) {
                int x = sc.nextInt();
                int y = sc.nextInt();
                v[y].add(x);
            }
            for (int i = 1; i <= n; i++) {
                check(i);
            }


    }
}