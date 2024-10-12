import java.io.*;
import java.util.*;
public class Main {
    static int K, k;

    static boolean find = false;
    static void select(int[] arr, int rr, int q) {
        int l = 0, r = rr;
        while (l <= r) { //메모리 초과 방지하는 법 -> 재귀 대신 while 사용...
            int tmp = partition(arr, l, r);
            if (tmp == q - 1 ||find) return;
            if (q - 1 < tmp) r = tmp - 1;
            else l = tmp + 1;
        }
    }

    static int partition(int[] arr, int l, int r) {
        int pivot = arr[r];
        int i = l - 1; // pivot 보다 작은 값
        for (int j = l; j < r; j++) {
            if (arr[j] <= pivot) {
                i++;
                k++;
                if (K == k) {
                    if (arr[i] < arr[j]) System.out.print(arr[i] + " " + arr[j]);
                    else System.out.print(arr[j] + " " + arr[i]);
                    System.out.println();
                    find=true;
                    return j;
                }
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
        if (i + 1 != r) {
            k++;
            if (K == k) {
                if (arr[i+1] < arr[r]) System.out.print(arr[i+1] + " " + arr[r]);
                else System.out.print(arr[r] + " " + arr[i+1]);
                System.out.println();
                find=true;
            }
            int tmp = arr[i+1];
            arr[i+1] = arr[r];
            arr[r] = tmp;
        }
        return i+1;
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int Q = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        k=0;
        int[] arr = new int[N];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        select(arr, N - 1, Q);
        if (!find) System.out.println(-1);
        br.close();
    }
}