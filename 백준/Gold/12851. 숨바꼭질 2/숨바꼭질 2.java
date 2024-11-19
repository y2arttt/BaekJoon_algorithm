import java.util.*;

public class Main {
    static final int MAX = 100001;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int k = sc.nextInt();

        int[] dist = new int[MAX];
        int[] cnt = new int[MAX];

        Arrays.fill(dist, -1);

        Queue<Integer> q = new LinkedList<>();

        q.offer(n);
        dist[n] = 0;
        cnt[n] = 1;

        while (!q.isEmpty()) {
            int x = q.poll();

            if (x == k) break;

            int[] next = {x-1, x+1, x*2};
            for (int nx : next) {
                if (nx < 0 || nx >= MAX) continue;

                if (dist[nx] == -1) {
                    dist[nx] = dist[x] + 1;
                    cnt[nx] = cnt[x];
                    q.offer(nx);
                }
                else if (dist[nx] == dist[x] + 1) {
                    cnt[nx] += cnt[x];
                }
            }
        }

        System.out.println(dist[k]);
        System.out.println(cnt[k]);

        sc.close();
    }
}