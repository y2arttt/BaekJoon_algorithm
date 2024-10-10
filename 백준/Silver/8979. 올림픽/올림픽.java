import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n,k;
        n=sc.nextInt();
        k=sc.nextInt();
        int[][] arr = new int[n+1][3];
        for(int i=1;i<=n;i++){
            int a;
            a=sc.nextInt();
            for(int j=0; j<3; j++){
                arr[a][j]= sc.nextInt();
            }
        }
        int cnt=1;
        for(int i=1;i<=n;i++){
            if(i==k) continue;
            if(arr[i][0] > arr[k][0]){
                cnt++;
                continue;
            }
            else if(arr[i][0] == arr[k][0]){
                if(arr[i][1] > arr[k][1]){
                    cnt++;
                }
                else if(arr[i][1] == arr[k][1]){
                    if(arr[i][2] > arr[k][2]){
                        cnt++;
                    }
                }
            }
        }
        System.out.print(cnt);

    }

}
