#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string A,B;
    cin>>A>>B;
    int N[1001][1001];
    memset(N,0,sizeof(N));
    
    for(int i=1; i<=A.length(); i++){
        for(int j=1; j<=B.length(); j++){
            if(A[i-1] == B[j-1]){
                N[i][j] = N[i-1][j-1] +1;
            }
            else{
                N[i][j] = max(N[i-1][j],N[i][j-1]);
            }
        }
    }

    cout<<N[A.length()][B.length()];

    return 0;   
}