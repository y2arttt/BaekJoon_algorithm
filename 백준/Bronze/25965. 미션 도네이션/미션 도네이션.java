import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        for (int i = 0; i < n; i++) {
            int m = sc.nextInt();
            int[][] missions = new int[m][3];

            for (int j = 0; j < m; j++) {
                missions[j][0] = sc.nextInt();
                missions[j][1] = sc.nextInt();
                missions[j][2] = sc.nextInt();
            }

            int k = sc.nextInt();
            int d = sc.nextInt();
            int a = sc.nextInt();

            long sum = 0;
            for (int j = 0; j < m; j++) {
                long missionDonation = (long) k * missions[j][0] - (long) d * missions[j][1] + (long) a * missions[j][2];

                if (missionDonation > 0) {
                    sum += missionDonation;
                }
            }

            System.out.println(sum);
        }
        sc.close();
    }
}