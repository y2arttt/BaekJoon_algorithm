#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#define INF INT_MAX
using namespace std;

vector<vector<int>> edge(11, vector<int>(11,INF)); 
vector<vector<int>> map(10, vector<int>(10, 0)); 
vector <int> parents(10);

int check, n, m;

//간선 길이 구하기
int dfs(int i, int j, int mvi, int mvj, int cnt){
    int mj = j + mvj; 
    int mi = i + mvi; 
    if (mi >= 0 && mi < n && mj >= 0 && mj < m){
        if(map[mi][mj] == 0) return dfs(mi, mj, mvi, mvj, cnt + 1); 
        check = map[mi][mj]; 
    }
    
    return cnt;
}

//union find
int find(int n){
    if (parents[n] == n) return n;
    else return parents[n] = find(parents[n]);
}

void uni(int a, int b){
    int A = find(a);
    int B = find(b);
    if(A == B) return;
    parents[B] = A;
}


int main()
{
    

    int move[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> map[i][j];
            if (map[i][j] == 1) map[i][j] = -1;
        }
    }

    // 색칠
    int paint = 1;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (map[i][j] != -1) continue;
            map[i][j] = paint;
            queue<pair<int, int>> q;
            q.push({i, j});
            while (!q.empty()){
                int ii = q.front().first;
                int jj = q.front().second;
                q.pop();
                for (auto& mv : move){
                    int mj = jj + mv[1];
                    int mi = ii + mv[0];
                    
                    if (mi >= 0 && mi < n && mj >= 0 && mj < m && map[mi][mj] == -1){
                        map[mi][mj] = paint;
                        q.push({mi, mj});
                    }
                }
            }
            paint++;
        }
    }

    // 간선 확인
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (map[i][j] == 0) continue;
            for (auto& mv : move){
                int mj = j + mv[1];
                int mi = i + mv[0];
                if (mi >= 0 && mi < n && mj >= 0 && mj < m && map[mi][mj] == 0){
                    check = -1; 
                    int t = dfs(mi, mj, mv[0], mv[1], 1);
                    if(t <= 1 || check == map[i][j]) continue;
                    if (edge[map[i][j]][check] > t) edge[map[i][j]][check] = t;
                }
            }
        }
    }


    // 크루스칼 알고리즘

    // 큐 정의
    struct S_Edge {
        int start, end, weight;
        S_Edge(int s, int e, int w) : start(s), end(e), weight(w) {}
    };
    struct CompareEdge { 
        bool operator()(S_Edge const& e1, S_Edge const& e2) {
            return e1.weight > e2.weight;
        }
    };
    priority_queue<S_Edge, vector<S_Edge>, CompareEdge> pq;

    //우선순위 큐에 집어 넣음
    for (int i = 1; i < paint; i++){ 
        for (int j = i+1; j < paint; j++){ 
            if (edge[i][j] ==INF) continue;
            pq.push({i,j,edge[i][j]});      
        }
    }

    for(int i=0;i<10;i++) parents[i]=i;//parnets 초기화
    vector <bool> islands(7,false);//섬이 모두 연결되었는지 확인
    int result = 0;
    while (! pq.empty())
    {
        S_Edge eg = pq.top();
        pq.pop();
        int A = find(eg.start);
        int B = find(eg.end);
        if(A != B){
            uni(A,B);
            islands[A] = true;
            islands[B] = true;
            result += eg.weight;
        }
    }
    
    bool allConnected = true;
    for (int i = 1; i < paint; i++) {
        if (find(i) != find(1)) {
            allConnected = false;
            break;
        }
    }
    if (allConnected) {
        cout << result;
    } else {
        cout << -1;
    }

    return 0;
}
