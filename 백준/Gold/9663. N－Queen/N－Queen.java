import java.util.Scanner;

class Main {
    static int n;
    static int[] queens;
    static int count;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        queens = new int[n];
        count = 0;

        dfs(0);
        System.out.println(count);
    }

    static void dfs(int i) {
        if (i == n) {
            count++;
            return;
        }

        for (int j = 0; j < n; j++) {
            boolean valid = true;

            for (int k = 0; k < i; k++) {
                //열 비교 + 대각선 비교 - 행열거리가 같으면 대각선임
                if (queens[k] == j || Math.abs(queens[k] - j) == Math.abs(k - i)) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                queens[i] = j; 
                dfs(i + 1);
            }
        }
    }
}
