#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<pair<int, int>> jewel(n);
    vector<int> bag(k);
    
    for (int i = 0; i < n; i++) {
        cin >> jewel[i].first >> jewel[i].second;
    }
    
    for (int i = 0; i < k; i++) {
        cin >> bag[i];
    }
    
    sort(jewel.begin(), jewel.end());
    sort(bag.begin(), bag.end());

    priority_queue<int> pq;
    long long sum = 0;
    int idx = 0;
    
    for (int i = 0; i < k; i++) {
        while (idx < n && jewel[idx].first <= bag[i]) {
            pq.push(jewel[idx++].second);
        }
        if (!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
    }
    
    cout << sum;
    
    return 0;
}