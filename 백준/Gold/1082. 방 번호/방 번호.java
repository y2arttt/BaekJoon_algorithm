import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int[] p = new int[n];

        for (int i = 0; i < n; i++) {
            p[i] = sc.nextInt();
        }

        int m = sc.nextInt();

        // 첫 자리는 0이 올 수 없음 → 1부터 시작
        int minFirstPrice = 51;
        int minFirstI = -1;
        for (int i = 1; i < n; i++) {
            if (p[i] < minFirstPrice) {
                minFirstPrice = p[i];
                minFirstI = i;
            }
        }

        // 첫 자리도 못 사면 0
        if (minFirstI == -1 || minFirstPrice > m) {
            System.out.println(0);
            return;
        }

        // 전체 최소값 (0 포함)
        int minPrice = 51;
        int minI = -1;
        for (int i = 0; i < n; i++) {
            if (p[i] < minPrice) {
                minPrice = p[i];
                minI = i;
            }
        }

        // 첫 자리 먼저 구매
        m -= minFirstPrice;
        int k = 1 + m / minPrice; // 전체 자리수

        int[] num = new int[k];
        Arrays.fill(num, minI);
        num[0] = minFirstI;

        // 이미 사용한 돈 반영
        m -= (k - 1) * minPrice;

        // 가장 큰 수로 교체
        for (int i = 0; i < k; i++) {
            for (int j = n - 1; j >= 0; j--) {
                int cost = (i == 0 ? minFirstPrice : minPrice);
                if (m + cost >= p[j]) {
                    m = m + cost - p[j];
                    num[i] = j;
                    break;
                }
            }
        }

        for (int i = 0; i < k; i++) {
            System.out.print(num[i]);
        }
    }
}
