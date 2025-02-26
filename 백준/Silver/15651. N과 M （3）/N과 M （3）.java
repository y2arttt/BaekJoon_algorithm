import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

class Main {
    static int n, m;
    static int[] result;
    static StringBuilder sb = new StringBuilder(); 

    static void dfs(int k) {
        if (k == m) {
            for (int i : result) {
                sb.append(i).append(" "); 
            }
            sb.append("\n");
            return;
        }

        for (int i = 1; i <= n; i++) {
            result[k] = i;
            dfs(k + 1);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        result = new int[m];

        dfs(0);

        System.out.print(sb.toString());
    }
}
