import java.util.Scanner;

public class Main {


    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] p= new int[n+1];
        for(int i=1;i<=n;i++){
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            p[i-1]=a;
            p[i]=b;
        }
        int[][] m = new int[n+1][n+1];
        for(int i=1;i<=n;i++){
            m[i][i] = 0;
        }
        for(int r=2;r<=n;r++){
            for(int i=1;i<=n-r+1;i++){
                int j =i+r-1;
                int minValue = Integer.MAX_VALUE;
                for(int k=i;k<=j-1;k++){
                    minValue = Math.min(minValue,m[i][k]+m[k+1][j]+(p[i-1]*p[k]*p[j]));
                }
                m[i][j] = minValue;
            }
        }
        System.out.println(m[1][n]);
    }
}
