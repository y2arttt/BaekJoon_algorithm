import java.util.*;

public class Main {
    static int n, l;
    static int[][] map;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        l = sc.nextInt();

        map = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                map[i][j] = sc.nextInt();
            }
        }

        int cnt = 0;

        // 행 체크
        for (int i = 0; i < n; i++) {
            if (check(map[i])) cnt++;
        }

        // 열 체크
        for (int i = 0; i < n; i++) {
            int[] colArr = new int[n];
            for (int j = 0; j < n; j++) colArr[j] = map[j][i];
            if (check(colArr)) cnt++;
        }

        System.out.println(cnt);
    }

    static boolean check(int[] arr) {
        boolean[] isIncline = new boolean[n];

        for (int i = 0; i < n - 1; i++) {
            int gap = arr[i] - arr[i + 1];

            if (Math.abs(gap) > 1) return false;

            // 오르막 (앞이 낮고 뒤가 높음)
            if (gap == -1) {
                for (int j = 0; j < l; j++) {
                    if (i - j < 0 || isIncline[i - j]) return false;
                    if (arr[i] != arr[i - j]) return false;
                    isIncline[i - j] = true;
                }
            }

            // 내리막 (앞이 높고 뒤가 낮음)
            else if (gap == 1) {
                for (int j = 1; j <= l; j++) {
                    if (i + j >= n || isIncline[i + j]) return false;
                    if (arr[i + 1] != arr[i + j]) return false;
                    isIncline[i + j] = true;
                }
            }
        }

        return true;
    }
}
