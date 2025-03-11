import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt(); 
        int w = sc.nextInt(); 
        int l = sc.nextInt(); 

        Queue<Integer> trucks = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            trucks.add(sc.nextInt());
        }

        Queue<Integer> bridge = new LinkedList<>();
        for (int i = 0; i < w; i++) {
            bridge.add(0); 
        }

        int time = 0;
        int currentWeight = 0;

        while (!trucks.isEmpty() || currentWeight > 0) {
            
            currentWeight -= bridge.poll();

            if (!trucks.isEmpty() && currentWeight + trucks.peek() <= l) {
                int truck = trucks.poll();
                bridge.add(truck);
                currentWeight += truck;
            } else {
                bridge.add(0); 
            }

            time++;
        }

        System.out.println(time);
    }
}