#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;
    cin>>n;
    int stair[301];
    int dp[301];
    dp[0]=0;
    for(int i=1; i<=n; i++){
        cin>>stair[i];
    }
    dp[1]=stair[1];
    dp[2]=stair[1]+stair[2];
    dp[3]=max(stair[1],stair[2])+stair[3];
    
    for(int i=4; i<=n; i++){
        dp[i] = max(dp[i-2], dp[i-3] + stair[i-1]) + stair[i];
    }
    cout<<dp[n];
    return 0;
}
