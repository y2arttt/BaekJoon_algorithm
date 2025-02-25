
import java.util.Arrays;
import java.util.Scanner;



class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] sumCoin  = new int[m+1];
        sumCoin[0] = 0;
        for (int i = 1; i <= m; i++) {
            sumCoin[i] = 100001;
        }
        int[] coin = new int[n];


        for (int i = 0; i < n; i++) {
            coin[i] = sc.nextInt();
        }
        Arrays.sort(coin);
        for (int i=0; i<n; i++) {
            for(int j=coin[i]; j<=m; j++){
                sumCoin[j] = Math.min(sumCoin[j],sumCoin[j-coin[i]]+1);
            }
        }
        if(sumCoin[m] == 100001){
            System.out.println("-1");
        }
        else System.out.println(sumCoin[m]);

    }
}