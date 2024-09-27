#include <iostream>
#include <algorithm>
using namespace std;

int n;
int t[1500001], p[1500001], dp[1500001];
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    cin >> n; 
    
    for(int i=1; i<=n; i++){
        cin>>t[i]>>p[i];
    }
    int currentMax=0;
    for(int i=1; i<=n; i++){
        currentMax= max(dp[i],currentMax);
        if(i+t[i] <= n+1){
            dp[i+t[i]] = max(dp[i+t[i]],currentMax+p[i]);
        }
    }
    cout<<max(currentMax, dp[n+1]);

    return 0;
}