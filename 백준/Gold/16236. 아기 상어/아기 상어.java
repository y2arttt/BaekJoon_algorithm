import java.util.*;

public class Main {
    static int[][] sea;
    static int n;
    static boolean[][] visited;
    static int[] dx = {-1, 0, 0, 1}; // 상, 좌, 우, 하
    static int[] dy = {0, -1, 1, 0};
    static int result = 0;
    static int babySharkLevel = 2, babySharkExp = 0;
    static int babySharkX, babySharkY;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();

        sea = new int[n][n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                sea[i][j] = sc.nextInt();
                if (sea[i][j] == 9) {
                    babySharkX = i;
                    babySharkY = j;
                    sea[i][j] = 0; // 아기상어가 있는 자리는 빈칸으로 처리
                }
            }
        }

        while (true) {
            int[] next = bfs(babySharkX, babySharkY);
            int nextX = next[0];
            int nextY = next[1];
            int distance = next[2];

            if (distance == -1) break; // 더 이상 먹을 물고기가 없음

            babySharkX = nextX;
            babySharkY = nextY;
            result += distance;

            babySharkExp++;
            if (babySharkExp == babySharkLevel) {
                babySharkLevel++;
                babySharkExp = 0;
            }

            sea[nextX][nextY] = 0; // 먹은 물고기 자리 비워줌
        }

        System.out.println(result);
    }

    static int[] bfs(int x, int y) {
        visited = new boolean[n][n];
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{x, y, 0});
        visited[x][y] = true;

        List<int[]> fishList = new ArrayList<>();
        int minDistance = Integer.MAX_VALUE;

        while (!queue.isEmpty()) {
            int[] now = queue.poll();
            int nowX = now[0];
            int nowY = now[1];
            int dist = now[2];

            // 현재 거리보다 더 먼 곳은 볼 필요 없음
            if (dist > minDistance) continue;

            // 먹을 수 있는 물고기인지 확인
            if (sea[nowX][nowY] != 0 && sea[nowX][nowY] < babySharkLevel) {
                fishList.add(new int[]{nowX, nowY, dist});
                minDistance = dist;
                continue; // 같은 거리의 다른 후보도 계속 탐색
            }

            // 4방향 탐색
            for (int i = 0; i < 4; i++) {
                int nextX = nowX + dx[i];
                int nextY = nowY + dy[i];

                if (nextX < 0 || nextY < 0 || nextX >= n || nextY >= n) continue;
                if (visited[nextX][nextY]) continue;
                if (sea[nextX][nextY] > babySharkLevel) continue;

                visited[nextX][nextY] = true;
                queue.offer(new int[]{nextX, nextY, dist + 1});
            }
        }

        if (fishList.isEmpty()) {
            return new int[]{-1, -1, -1}; // 못 찾음
        }

        // 가장 위, 가장 왼쪽 우선 정렬
        fishList.sort((a, b) -> {
            if (a[0] == b[0]) {
                return Integer.compare(a[1], b[1]);
            }
            return Integer.compare(a[0], b[0]);
        });

        return fishList.get(0); // 가장 우선순위 높은 물고기 리턴
    }
}


