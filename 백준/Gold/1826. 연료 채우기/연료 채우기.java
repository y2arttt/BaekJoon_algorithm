import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        int[][] map = new int[n][2];
        for (int i = 0; i < n; i++) {
            map[i][0] = sc.nextInt();
            map[i][1] = sc.nextInt();
        }

        int finish = sc.nextInt();
        int currentFuel = sc.nextInt(); 


        Arrays.sort(map, (a, b) -> a[0] - b[0]);


        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());

        int cnt = 0;
        int i = 0;

        while (currentFuel < finish) {

            while (i < n && map[i][0] <= currentFuel) {
                pq.offer(map[i][1]);
                i++;
            }


            if (pq.isEmpty()) {
                System.out.println(-1);
                return;
            }

            currentFuel += pq.poll();
            cnt++;
        }

        System.out.println(cnt);
    }
}