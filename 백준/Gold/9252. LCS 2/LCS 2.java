import java.util.Scanner;
import java.util.Stack;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String n = scanner.nextLine();
        String m = scanner.nextLine();
        int[][] dp = new int[m.length() + 1][n.length() + 1];

        for (int i = 0; i <= m.length(); i++) {
            dp[i][0] = 0;
        }
        for (int j = 0; j <= n.length(); j++) {
            dp[0][j] = 0;
        }

        for(int i = 1; i <= m.length(); i++) {
            for(int j = 1; j <= n.length(); j++) {
                if(n.charAt(j - 1) == m.charAt(i - 1)) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        Stack<Character> s = new Stack<>();
        int i = m.length(), j = n.length(), c = dp[i][j];
        System.out.println(c);

        while (c != 0){
            if(dp[i-1][j] == c){
                i--;
            }
            else if(dp[i][j-1] == c){
                j--;
            }
            else{
                c--;
                s.add(n.charAt(j-1));
                i--;
                j--;
            }
        }

        while(!s.isEmpty()){
            System.out.print(s.pop());
        }
    }
}