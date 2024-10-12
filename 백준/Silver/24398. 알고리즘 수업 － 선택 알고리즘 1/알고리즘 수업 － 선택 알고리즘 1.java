import java.io.*;
import java.util.*;

public class Main {
    static int K, k;
    static boolean find = false;

    static void select(int[] arr, int N, int Q) {
        int l = 0, r = N - 1;
        while (l <= r) {
            int pivot = partition(arr, l, r);
            if (pivot == Q - 1 || find) return;
            if (Q - 1 < pivot) r = pivot - 1;
            else l = pivot + 1;
        }
    }

    static int partition(int[] arr, int l, int r) {
        int pivot = arr[r];
        int i = l - 1;
        for (int j = l; j < r; j++) {
            if (arr[j] <= pivot) {
                i++;
                swap(arr, i, j);
            }
        }
        if(i+1!=r) swap(arr, i + 1, r);
        return i + 1;
    }

    static void swap(int[] arr, int i, int j) {
        k++;
        if (K == k) {
            if (arr[i] < arr[j]) System.out.println(arr[i] + " " + arr[j]);
            else System.out.println(arr[j] + " " + arr[i]);
            find = true;
        }
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int Q = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        k = 0;

        int[] arr = new int[N];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        select(arr, N, Q);
        if (!find) System.out.println(-1);
        br.close();
    }
}