import java.util.Scanner;
import java.util.ArrayList;

public class Main {
    static ArrayList<Integer> frq = new ArrayList<>();

    static int binarySearch(int value) {
        int s = 0;
        int e = frq.size() - 1;

        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (frq.get(mid) < value) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return s;
    }

    public static void main(String[] args) {
        int[] arr = new int[1000000];
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }


        frq.add(arr[0]);

        for (int i = 1; i < n; i++) {
            int pos = binarySearch(arr[i]);
            if (pos == frq.size()) {
                frq.add(arr[i]);
            } else {
                frq.set(pos, arr[i]);
            }
        }

        System.out.println(frq.size());
        scanner.close();
    }
}