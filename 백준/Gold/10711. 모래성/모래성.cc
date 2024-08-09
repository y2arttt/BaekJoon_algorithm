#include <iostream>
#include <climits> 
#include <queue>
#include <vector>
#include <string>

using namespace std;
int h,w;
vector<vector<int>> maps(1000,vector<int>(1000));
int move_i[8] = {-1,-1,-1,0,0,1,1,1};
int move_j[8] = {-1,0,1,-1,1,-1,0,1};
queue <pair<int,int>> q;


// 문자열 그래프 나오면 숫자로 치환해보기
//나는 모래성 주변을 찾아보려했는데, . 주변을 찾아 -1씩 하면 됐음
int bfs(){
    int cnt=0;
    while (1)
    {
        int size = q.size();
        for(int i=0; i<size; i++){
            int ci = q.front().first;
            int cj = q.front().second;
            q.pop();
            for(int j=0; j<8; j++){
                int di = ci + move_i[j];
                int dj = cj + move_j[j];
                if(di < 0 || di >= h || dj <0 || dj >= w)   continue;
                if(--maps[di][dj] == 0){
                    q.push({di,dj});
                }
                
            }
        }
        if(q.empty())break;
        cnt++;
    }
    return cnt;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); 


    cin>>h>>w;
    char c;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cin>>c;
            if(c == '.'){
                maps[i][j] = 0;
                q.push({i,j});
            }
            else maps[i][j] = c - '0';
        } 
    }

    cout<<bfs();
    


    return 0;
}
