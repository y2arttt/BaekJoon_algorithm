import java.util.*;

public class Main {
    public static void main(String[] args) {
            Scanner sc = new Scanner(System.in);
            int n = sc.nextInt();
            int[][] arr = new int[n][2];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < 2; j++) {
                    arr[i][j] = sc.nextInt();
                }
            }

            Arrays.sort(arr, (a, b) -> a[0] == b[0] ? b[1] - a[1] : a[0] - b[0]);
            PriorityQueue<Integer> pq = new PriorityQueue<>();
    
            for (int[] a : arr) {
                pq.offer(a[1]);
                if (pq.size() > a[0]) {
                    pq.poll();
                }
            }
    
            int cnt = 0;
            while (!pq.isEmpty()) {
                cnt += pq.poll();
            }

            System.out.println(cnt);
    }
}