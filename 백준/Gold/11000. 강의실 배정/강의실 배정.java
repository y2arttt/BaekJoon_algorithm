import java.util.*;


public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] time = new int[n][2];
        for (int i = 0; i < n; i++) {
            time[i][0] = sc.nextInt();
            time[i][1] = sc.nextInt();
        }
        Arrays.sort(time, (a, b) -> a[0] - b[0]);
        PriorityQueue<Integer> classRoom = new PriorityQueue<>();

        for (int i = 0; i < n; i++) {
            if(classRoom.isEmpty() || classRoom.peek() <=  time[i][0]) {
                classRoom.poll();

            }
            classRoom.add(time[i][1]);
        }
        System.out.println(classRoom.size());

    }
}
