import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int l = sc.nextInt();

        int[][] pool = new int[n][2];
        for (int i = 0; i < n; i++) {
            pool[i][0] = sc.nextInt();
            pool[i][1] = sc.nextInt();
        }

        Arrays.sort(pool, (a, b) -> a[0] - b[0]);

        int border = 0; 
        int cnt = 0;    

        for (int[] i : pool) {
            if (border < i[0]) {
                border = i[0];
            }

            while (border < i[1]) {
                border += l; 
                cnt++;      
            }
        }

        System.out.println(cnt);
    }
}