import java.util.*;

import static java.lang.Math.min;


public class Main {


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] price = new int[n][3];
        int[][] house = new int[n][3];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                price[i][j] = sc.nextInt();
                house[i][j] = 0;
            }
        }
        house[0][0] = price[0][0];
        house[0][1] = price[0][1];
        house[0][2] = price[0][2];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                if(j == 0){
                    house[i][j] = min(house[i-1][1],house[i-1][2])+price[i][j];
                }
                else if(j == 1){
                    house[i][j] = min(house[i-1][0],house[i-1][2])+price[i][j];
                }
                else house[i][j] = min(house[i-1][0],house[i-1][1])+price[i][j];
            }
        }
        System.out.println(min(min(house[n-1][0], house[n-1][2]),house[n-1][1]));

    }
}