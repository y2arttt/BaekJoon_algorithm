import java.util.*;

public class Main {
    static final int MAX = 100001;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int k = sc.nextInt();

        int[] dist = new int[MAX];
        Arrays.fill(dist, Integer.MAX_VALUE);

        PriorityQueue<int[]> q = new PriorityQueue<>((a, b) -> a[1] - b[1]);
        q.add(new int[]{n, 0});
        dist[n] = 0;

        while (!q.isEmpty()) {
            int[] curq = q.poll();
            int cur = curq[0];
            int crt = curq[1];

            if (cur == k) {
                System.out.println(crt);
                return;
            }

            if (cur * 2 < MAX && crt < dist[cur * 2]) {
                dist[cur * 2] = crt;
                q.add(new int[]{cur * 2, crt});
            }

            if (cur + 1 < MAX && crt + 1 < dist[cur + 1]) {
                dist[cur + 1] = crt + 1;
                q.add(new int[]{cur + 1, crt + 1});
            }

            if (cur - 1 >= 0 && crt + 1 < dist[cur - 1]) {
                dist[cur - 1] = crt + 1;
                q.add(new int[]{cur - 1, crt + 1});
            }
        }
    }
}
