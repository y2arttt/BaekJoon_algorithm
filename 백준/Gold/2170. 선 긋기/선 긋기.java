import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[][] line = new int[n][2];

        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            line[i][0] = Integer.parseInt(st.nextToken());
            line[i][1] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(line, Comparator.comparingInt(a -> a[0]));

        int start = line[0][0];
        int end = line[0][1];
        long totalLength = 0; 

        for (int i = 1; i < n; i++) {
            if (line[i][0] > end) {
                totalLength += end - start;
                start = line[i][0];
                end = line[i][1];
            } else {
                end = Math.max(end, line[i][1]);
            }
        }

        totalLength += end - start;

        System.out.println(totalLength);
        br.close();
    }
}