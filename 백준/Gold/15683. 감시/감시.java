import java.util.*;

public class Main {
    static int[][] map;
    static int n, m;
    static List<int[]> cctv = new ArrayList<>();
    static int min = Integer.MAX_VALUE;

    // 방향: 상, 우, 하, 좌
    static int[] dx = {-1, 0, 1, 0};
    static int[] dy = {0, 1, 0, -1};

    // 각 CCTV 타입별 감시 방향
    static int[][][] cctvDir = {
            {},  // 인덱스 0은 사용하지 않음
            {{0}, {1}, {2}, {3}},  // 1번: 한 방향
            {{0, 2}, {1, 3}},  // 2번: 상하 또는 좌우
            {{0, 1}, {1, 2}, {2, 3}, {3, 0}},  // 3번: 직각 방향
            {{0, 1, 2}, {1, 2, 3}, {2, 3, 0}, {3, 0, 1}},  // 4번: 세 방향
            {{0, 1, 2, 3}}  // 5번: 네 방향
    };

    static void dfs(int ctNum) {
        if (ctNum == cctv.size()) {
            // 사각지대 계산
            int count = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (map[i][j] == 0) {
                        count++;
                    }
                }
            }
            min = Math.min(min, count);
            return;
        }

        int[] current = cctv.get(ctNum);
        int type = map[current[0]][current[1]];
        int x = current[0];
        int y = current[1];

        // 임시 맵 복사
        int[][] tmpMap = new int[n][m];

        // 해당 CCTV 타입의 모든 감시 방향 조합에 대해 처리
        for (int[] dirs : cctvDir[type]) {
            // 맵 복사
            for (int i = 0; i < n; i++) {
                tmpMap[i] = map[i].clone();
            }

            // 감시 영역 표시
            for (int dir : dirs) {
                watch(x, y, dir);
            }

            // 다음 CCTV 처리
            dfs(ctNum + 1);

            // 맵 복원
            for (int i = 0; i < n; i++) {
                map[i] = tmpMap[i].clone();
            }
        }
    }

    // 특정 방향으로 감시 영역 표시
    static void watch(int x, int y, int dir) {
        int nx = x;
        int ny = y;

        while (true) {
            nx += dx[dir];
            ny += dy[dir];

            // 맵 범위를 벗어나면 종료
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                break;
            }

            // 벽을 만나면 종료
            if (map[nx][ny] == 6) {
                break;
            }

            // CCTV는 통과 가능
            if (map[nx][ny] >= 1 && map[nx][ny] <= 5) {
                continue;
            }

            // 감시 영역 표시 (-1로 표시)
            map[nx][ny] = -1;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        map = new int[n][m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                map[i][j] = sc.nextInt();
                if (map[i][j] >= 1 && map[i][j] <= 5) {
                    cctv.add(new int[]{i, j}); // 행(i), 열(j) 순서로 저장
                }
            }
        }

        dfs(0);
        System.out.println(min);
    }
}