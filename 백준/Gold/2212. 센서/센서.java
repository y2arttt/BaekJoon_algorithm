import java.util.*;


public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] sensor = new int[n];
        for (int i = 0; i < n; i++) {
            sensor[i] = sc.nextInt();
        }
        Arrays.sort(sensor);
        int[] diff = new int[n];
        for (int i = 0; i < n; i++) {
            if(i == n - 1) diff[i] = 0;
            else diff[i] = sensor[i+1] - sensor[i];
        }
        Arrays.sort(diff);
        int result = 0;
        for(int i = 0; i<n-k+1; i++){
            result += diff[i];
        }
        System.out.println(result);
    }
}
