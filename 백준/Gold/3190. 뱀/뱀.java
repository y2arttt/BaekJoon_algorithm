import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] dx = {0,1,0,-1};
        int[] dy = {1,0,-1,0};


        int[] directionChange = new int[10001];
        Arrays.fill(directionChange, 0);

        int n = sc.nextInt();
        int k = sc.nextInt();
        ArrayList<int[]> apples = new ArrayList<>();

        for (int i = 0; i < k; i++) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            apples.add(new int[]{x, y});
        }

        int l = sc.nextInt();
        for (int i = 0; i < l; i++) {
            int time = sc.nextInt();
            char direction = sc.next().charAt(0);
            if (direction == 'L') {
                directionChange[time] = -1;
            } else {
                directionChange[time] = 1;
            }
        }

        Deque<int[]> snake = new LinkedList<>();
        snake.addFirst(new int[]{1, 1});
        int currentTime = 0;
        int snakeDirection = 0;

        while (true) {
            currentTime++;
            snakeDirection = (snakeDirection + directionChange[currentTime - 1] + 4) % 4;

            int[] head = snake.getFirst();
            int nx = head[0] + dx[snakeDirection];
            int ny = head[1] + dy[snakeDirection];


            if (isGameOver(nx, n, ny, snake)) {
                break;
            }


            snake.addFirst(new int[]{nx, ny});

            boolean foundApple = appleCheck(apples, nx, ny);

            if (!foundApple) {
                snake.pollLast();
            }
        }

        System.out.println(currentTime);
    }

    private static boolean appleCheck(ArrayList<int[]> apples, int x, int y) {
        for (int i = 0; i < apples.size(); i++) {
            int[] apple = apples.get(i);
            if (apple[0] == x && apple[1] == y) {
                apples.remove(i);
                return true;
            }
        }
        return false;
    }

    private static boolean isGameOver(int x, int n, int y, Deque<int[]> snake) {
        if (x > n || x < 1 || y > n || y < 1) {
            return true;
        }

        Iterator<int[]> iterator = snake.iterator();
        if (iterator.hasNext()) {
            iterator.next();
        }

        while (iterator.hasNext()) {
            int[] body = iterator.next();
            if (body[0] == x && body[1] == y) {
                return true;
            }
        }
        return false;
    }
}