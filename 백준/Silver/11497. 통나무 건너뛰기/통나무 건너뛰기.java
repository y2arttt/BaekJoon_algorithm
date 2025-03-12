import java.util.*;

import static java.lang.Math.abs;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        for (int i = 0; i < t; i++) {
            int n = sc.nextInt();
            int[] logs = new int[n];

            for (int j = 0; j < n; j++) {
                logs[j] = sc.nextInt();
            }

            Arrays.sort(logs);

            int[] result = new int[n];
            int left = 0;
            int right = n - 1;
            boolean toggle = true;
            
            for (int j = n - 1; j >= 0; j--) {
                if (toggle) {
                    result[left++] = logs[j];
                } else {
                    result[right--] = logs[j];
                }
                toggle = !toggle;
            }

            int max = 0;

            for (int j = 0; j < n; j++) {
                int next = (j + 1) % n;
                max = Math.max(max, abs(result[j] - result[next]));
            }

            System.out.println(max);
        }
    }
}
