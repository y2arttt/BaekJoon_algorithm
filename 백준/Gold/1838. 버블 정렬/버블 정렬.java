import java.util.*;
import java.io.*;
 
// https://www.acmicpc.net/problem/1838
 
class Main {
    static int stoi(String s) { return Integer.parseInt(s);}
 
    static class Pair implements Comparable<Pair> {
        int index;
        long value;
 
        public Pair(int index, long value) {
            this.index = index;
            this.value = value;
        }
 
        public int compareTo(Pair o) {
            return (int) (this.value - o.value);
        }
 
    }
 
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
 
        int n = stoi(br.readLine());
        int max = 0;
        PriorityQueue<Pair> pq = new PriorityQueue<Pair>();
 
        st = new StringTokenizer(br.readLine());
        for(int i=0; i<n; i++) {
            pq.add(new Pair(i, stoi(st.nextToken())));
        }
 
        int idx = 0;
        while(!pq.isEmpty()) {
            Pair pair = pq.poll();
 
            if(max < pair.index - idx)
                max = pair.index - idx;
 
            idx++;
        }
 
        System.out.println(max);
    }
}