#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> seq(n + 1);
    vector<int> res;

    for(int i = 1; i <= n; i++){
        cin >> seq[i];
    }

    res.push_back(seq[1]);
    
    for(int i = 2; i <= n; i++){
        if(seq[i] > res.back()) {
            res.push_back(seq[i]);
        } else {
            auto it = lower_bound(res.begin(), res.end(), seq[i]);
            *it = seq[i];
        }
    }
    
    cout << res.size() << endl;
    
    return 0;
}