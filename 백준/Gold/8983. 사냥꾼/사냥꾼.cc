#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    int n,m,l;
    cin>>m>>n>>l;
    int hunter[100000];
    for(int i=0; i<m; i++){
        cin>>hunter[i];
    }
    sort(hunter,hunter+m);
    int cnt = 0;
    for(int i=0; i<n; i++){
        int x,y;
        cin>>x>>y;
        if(y>l) continue;
        long long max = l+x-y;
        long long min = x+y-l;
        auto it = lower_bound(hunter, hunter + m, min);
        if(it != hunter+m && *it <= max ) cnt++;
    }
    cout<<cnt;
    
    return 0;
}
