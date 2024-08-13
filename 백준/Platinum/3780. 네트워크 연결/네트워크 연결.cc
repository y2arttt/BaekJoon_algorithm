#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

vector<int> parents(200001);
vector<int> companys(200001);

int find(int c){
    if(c == parents[c]) return c;
    int root = find(parents[c]);
    companys[c] += companys[parents[c]];
    return parents[c] = root;
}

void uni(int i, int j){

    companys[i] = abs(i-j)%1000;
    parents[i] = j;
    
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int t,n;
    cin>>t;
    while (t--)
    {
        cin>>n;
        for(int i=1; i<=n; i++){
            parents[i]=i;
            companys[i] = 0;
        }
        char x;
        while (cin>>x && x != 'O')
        {
            int i,j;
            if(x == 'E'){
                cin>>i;
                find(i);
                cout<<companys[i]<<'\n';
            }
            else{
                cin>>i>>j;
                uni(i,j);
            }
        }
        
    }
    

    return 0;   
}