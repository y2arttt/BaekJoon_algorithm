import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        Integer[] crane = new Integer[n];
        for (int i = 0; i < n; i++) {
            crane[i] = sc.nextInt();
        }

        Arrays.sort(crane, Collections.reverseOrder());  

        int m = sc.nextInt();
        ArrayList<Integer> boxes = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            boxes.add(sc.nextInt());
        }

        Collections.sort(boxes, Collections.reverseOrder());  

        if (boxes.get(0) > crane[0]) {
            System.out.println(-1);
            return;
        }

        int time = 0;

        while (!boxes.isEmpty()) {
            int boxIdx = 0;  
            for (int i = 0; i < n;) { 
                if (boxIdx == boxes.size()) break;  

                if (crane[i] >= boxes.get(boxIdx)) {
                    boxes.remove(boxIdx);  
                    i++; 
                } else {
                    boxIdx++;  
                }
            }
            time++;
        }

        System.out.println(time);
    }
}
