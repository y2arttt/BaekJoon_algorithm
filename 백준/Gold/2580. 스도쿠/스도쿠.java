import java.util.*;

class Main {
    static int[][] map;
    static ArrayList<int[]> list;
    static int length;
    static void dfs(int l){
        if(l == length) return;
        int[] tmp = list.get(l);
        int i = tmp[0];
        int j = tmp[1];
        for(int k=1; k<10; k++){

            if(isValid(i,j,k)){
                map[i][j] = k;
                dfs(l+1);
                if (allFilled()) { // 모든 칸이 채워졌다면
                    return;
                }
                map[i][j] = 0;
            }


        }
    }
    static boolean allFilled() {
        // 모든 칸이 채워졌는지 확인
        for (int i = 1; i < 10; i++) {
            for (int j = 1; j < 10; j++) {
                if (map[i][j] == 0) {
                    return false;
                }
            }
        }
        return true;
    }
    static boolean isValid(int i,int j, int k){
            for(int l = 1; l < 10; l++){
                if(map[i][l] == k){
                    return false;
                }
            }
            for(int l = 1; l < 10; l++){
                if(map[l][j] == k){
                    return false;
                }
            }
            int startX = ((i-1)/3)*3 + 1;
            int startY = ((j-1)/3)*3 + 1;
            for(int x = startX; x<startX+3; x++){
                for(int y = startY; y<startY+3; y++){
                    if(map[x][y] == k){
                        return false;
                    }
                }
            }
            return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        map = new int[10][10];
        list = new ArrayList<>();

        for (int i = 1; i < 10; i++) {
            for (int j = 1; j < 10; j++) {
                map[i][j] = sc.nextInt();
                if(map[i][j] == 0){
                    list.add(new int[]{i, j});
                }
            }
        }
        length = list.size();

        dfs(0);
        for(int i =1; i<10; i++){
            for(int j =1; j<10; j++){
                System.out.print(map[i][j] + " ");
            }
            System.out.println();
        }

    }
}
