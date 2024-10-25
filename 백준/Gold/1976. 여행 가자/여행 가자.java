import java.util.Scanner;

public class Main {
    static int[] p = new int[201];

    static int find(int x) {
        if (p[x] == x) return x;
        return p[x] = find(p[x]);
    }

    static void uni(int x, int y) {
        x = find(x);
        y = find(y);
        if (x < y) p[y] = x;
        else p[x] = y;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();

        for (int i = 1; i <= n; i++) p[i] = i;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int x = sc.nextInt();
                if (x == 1) {
                    uni(i, j);
                }
            }
        }

        int root = -1;
        for (int i = 0; i < m; i++) {
            int x = sc.nextInt();
            if (i == 0) root = find(x);
            else {
                if (find(root) != find(x)) {
                    System.out.println("NO");
                    return;
                }
            }
        }
        System.out.println("YES");
    }
}