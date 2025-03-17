import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] students = new int[n];
        for(int i = 0; i < n; i++) {
            students[i] = sc.nextInt();
        }
        
        // 학생들 사이의 거리 차이 계산
        int[] next = new int[n-1];
        for(int i = 0; i < n-1; i++) {
            next[i] = students[i+1] - students[i];
        }
        
        // 거리 차이를 오름차순으로 정렬
        Arrays.sort(next);
        
        int result = 0;
        // 가장 큰 (k-1)개의 간격을 제외하고 모든 간격을 합산
        for(int i = 0; i < n-k; i++) {
            result += next[i];
        }
        
        System.out.println(result);
    }
}
