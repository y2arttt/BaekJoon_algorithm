import java.util.*;

class boxes implements Comparable<boxes> {
    int start;
    int end;
    int weight;

    public boxes(int s, int e, int w) {
        start = s;
        end = e;
        weight = w;
    }

    @Override
    public int compareTo(boxes o) {
        if (this.end == o.end) {
            return this.start - o.start;
        }
        return this.end - o.end;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int c = sc.nextInt();
        int m = sc.nextInt();

        boxes[] boxes = new boxes[m];
        for (int i = 0; i < m; i++) {
            boxes[i] = new boxes(sc.nextInt(), sc.nextInt(), sc.nextInt());
        }

        Arrays.sort(boxes);

        int[] village = new int[n + 1];
        int cnt = 0;

        for (boxes box : boxes) {
            int maxC = c;

            for (int i = box.start; i < box.end; i++) {
                maxC = Math.min(maxC, c - village[i]);
            }

            int lowWeight = Math.min(box.weight, maxC);

            for (int i = box.start; i < box.end; i++) {
                village[i] += lowWeight;
            }

            cnt += lowWeight;
        }

        System.out.println(cnt);
    }
}