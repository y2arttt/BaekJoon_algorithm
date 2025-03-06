import java.util.*;

public class Main {
    static int n, s, cnt;
    static int[] arr;

    static void dfs(int idx, int sum, int count) {
        if (idx == n) {
            if (sum == s && count > 0) {
                cnt++;
            }
            return;
        }

        dfs(idx + 1, sum + arr[idx], count + 1);
        dfs(idx + 1, sum, count);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        s = sc.nextInt();

        arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        dfs(0, 0, 0);
        System.out.println(cnt);
    }
}