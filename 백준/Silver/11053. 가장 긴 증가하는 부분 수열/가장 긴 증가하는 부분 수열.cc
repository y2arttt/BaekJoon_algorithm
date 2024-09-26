#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;
    cin>>n;
    int arr[1001];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    vector <int> freq;
    freq.push_back(arr[0]);
    for(int i=1; i<n; i++){
        auto lower = lower_bound(freq.begin(),freq.end(),arr[i]);
        if(lower == freq.end()) freq.push_back(arr[i]);
        else *lower = arr[i];
    }
    cout<<freq.size();
    return 0;
}
