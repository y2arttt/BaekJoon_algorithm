
import java.util.Scanner;

class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] boxSize  = new int[1001];
        for(int i = 1; i <= 1000; i++){
            boxSize[i] = 0;
        }
        int[] box = new int[n];
        for(int i = 0; i < n; i++){
            box[i] = sc.nextInt();
        }
        int maxSize = 0;
        for(int i = 0; i < n; i++){
            int max= 0;
            for(int j = 1; j < box[i]; j++){
                max = Math.max(max, boxSize[j]);
            }
            boxSize[box[i]] = max+1;
            maxSize = Math.max(maxSize, boxSize[box[i]]);
        }
        System.out.println(maxSize);
    }
}