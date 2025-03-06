import java.util.*;

class Main {

    static int n;
    static int[] arrays;
    static int[] operator = new int[4];
    static int max = Integer.MIN_VALUE;
    static int min = Integer.MAX_VALUE;
    static void dfs(int sum,int m){
        if(m == n){
            max = Math.max(max,sum);
            min = Math.min(min,sum);
            return;
        }
        for(int i = 0; i<4; i++){
            if(operator[i] > 0){
                operator[i]--;
                int tmp;
                if(i == 0){
                    tmp = sum + arrays[m];
                }
                else if(i == 1){
                    tmp = sum - arrays[m];
                }
                else if(i == 2){
                    tmp = sum * arrays[m];
                }
                else {
                    tmp = sum / arrays[m];
                }
                dfs(tmp,m+1);
                operator[i]++;
            }
        }
    }





    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        arrays = new int[n];
        for(int i = 0; i < n; i++){
            arrays[i] = sc.nextInt();
        }
        for(int i=0; i<4; i++){
            operator[i] = sc.nextInt();
        }
        dfs(arrays[0],1);

        System.out.println(max);
        System.out.println(min);
    }
}
