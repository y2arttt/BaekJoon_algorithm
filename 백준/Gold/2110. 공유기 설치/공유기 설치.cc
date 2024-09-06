#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    int n;
    int m;
    int house[200000];

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> house[i];
    }
    sort(house, house + n);
    
    int min = 1, max = house[n-1] - house[0];
    int result = 0;
    
    while (min <= max) {
        int mid = (min + max) / 2;
        int current = house[0];
        int cnt = 1; 
        
        for(int i = 1; i < n; i++){
            if(house[i] - current >= mid) {
                cnt++;
                current = house[i];
            }
        }
        
        if(cnt >= m){
            result = mid;
            min = mid + 1;
        } else {
            max = mid - 1;
        }
    }
    
    cout << result;
    return 0;
}