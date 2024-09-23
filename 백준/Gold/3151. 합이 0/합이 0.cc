#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    int arr[10000];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    long long cnt=0;
    for(int i=0; i<n-2; i++){
        for(int j=i+1; j<n-1; j++){
            int tmp = arr[i] + arr[j];
            int lower = lower_bound(arr +(j+1), arr + n, -tmp) - arr;
            int upper = upper_bound(arr+(j+1), arr + n, -tmp) - arr;
            cnt +=  upper - lower ; 
        }
    }
    cout<<cnt;
    return 0;
}