
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int[][] lectures = new int[n][2];

        for (int i = 0; i < n; i++) {
            int tmp = sc.nextInt(); 
            int start = sc.nextInt();
            int end = sc.nextInt();
            lectures[i][0] = start;
            lectures[i][1] = end;
        }

        Arrays.sort(lectures, (a, b) -> Integer.compare(a[0], b[0]));

        PriorityQueue<Integer> pq = new PriorityQueue<>();

        pq.add(lectures[0][1]); 

        for (int i = 1; i < n; i++) {
            int start = lectures[i][0];
            int end = lectures[i][1];

            if (pq.peek() <= start) {
                pq.poll();
            }

            pq.add(end);
        }

        System.out.println(pq.size()); 
    }
}

