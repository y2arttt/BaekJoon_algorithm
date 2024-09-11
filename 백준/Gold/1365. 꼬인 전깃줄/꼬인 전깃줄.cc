#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    int n;
    cin>>n;
    int arr[100000];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    vector <int> frq;
    frq.push_back(arr[0]);
    for(int i=1; i<n; i++){
        if(arr[i] > frq.back()) frq.push_back(arr[i]);
        else {
            auto lt = upper_bound(frq.begin(), frq.end(), arr[i]);
            *lt = arr[i];
        }
        
    }
    cout<<n-frq.size();

    
    return 0;
}
