import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.Vector;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int[] p = new int[n];
        Vector<Vector<Integer>> v = new Vector<>(n);

        for (int i = 0; i < n; i++) {
            v.add(new Vector<>());
        }

        int root = -1;
        for (int i = 0; i < n; i++) {
            p[i] = sc.nextInt();
            if (p[i] == -1) {
                root = i;
            } else {
                v.get(p[i]).add(i);
            }
        }

        int del = sc.nextInt();
        if (del == root) {
            System.out.println(0);
            return;
        }

        v.get(p[del]).remove(Integer.valueOf(del));

        Queue<Integer> q = new LinkedList<>();
        q.add(root);
        int cnt = 0;

        while (!q.isEmpty()) {
            int cur = q.poll();
            if (cur == del) continue;

            if (v.get(cur).isEmpty()) {
                cnt++;
            } else {
                for (int next : v.get(cur)) {
                    q.add(next);
                }
            }
        }

        System.out.println(cnt);
    }
}