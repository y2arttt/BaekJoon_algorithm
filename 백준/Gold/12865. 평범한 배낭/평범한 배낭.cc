#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    vector<pair<int,int>> obj(N+1);
    for (int i = 1; i <= N; i++) {
        int W, V;
        cin >> W >> V;
        obj[i] = {W, V};
    }

    vector<vector<int>> backpack(N+1, vector<int>(M+1, 0));
    
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            int weight = obj[i].first;
            int value = obj[i].second;
            if(weight <= j){
                backpack[i][j] = max(backpack[i-1][j], backpack[i-1][j-weight] + value);
            }
            else{
                backpack[i][j] = backpack[i-1][j];
            }
        }
    }
    cout << backpack[N][M];
    return 0;
}