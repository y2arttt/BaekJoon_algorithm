import java.util.*;

public class Main {
    public static void main(String[] args)  {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        int[] cnt = {0,0,0,0,0};
        char[] uospc = {'u', 'o', 's', 'p', 'c'};
        String s = sc.nextLine();
        for (int i = 0; i < n; i++) {
            for(int j = 0; j < 5; j++) {
                if(s.charAt(i) == uospc[j]) {
                    cnt[j]++;
                }
            }
        }
        int min = Integer.MAX_VALUE;
        for(int i = 0; i < 5; i++){
            min = Math.min(min, cnt[i]);
        }
        System.out.println(min);

    }
}