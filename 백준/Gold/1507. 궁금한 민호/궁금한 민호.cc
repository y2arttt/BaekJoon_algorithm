#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int>> maps(21,vector<int>(21));

void floyd (){
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0+i; j<n; j++){
                if(maps[i][k] == 0 || maps[k][j] == 0) continue;
                if(maps[i][j] > (maps[i][k] + maps[k][j])){
                    cout<<-1;
                    return;
                }

                if(maps[i][j] == (maps[i][k] + maps[k][j])){
                    maps[i][j]=0;
                    maps[j][i]=0;
                }
            }
        }
    }
    int sum=0;
    for(int i=0; i<n; i++){
        for(int j=0+i; j<n; j++){
            sum+=maps[i][j];
        }
    }
    cout<<sum;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); 
    
    
    cin>>n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>maps[i][j];
        }
    }
    floyd();


    return 0;
}
