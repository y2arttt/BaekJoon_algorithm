import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] p = new int[n];

        for (int i = 0; i < n; i++) {
            p[i] = scanner.nextInt();
        }

        int maxSum = p[0];
        int currentSum = p[0];

        for (int i = 1; i < n; i++) {
            currentSum = Math.max(p[i], currentSum + p[i]);
            maxSum = Math.max(maxSum, currentSum);
        }

        System.out.println(maxSum);
    }
}