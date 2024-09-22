#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    int arr[100000];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int result= INT_MAX;   
    int left = 0, right = 0;
    while (right < n)
    {
        int tmp = arr[right] - arr[left];
        if(tmp >= m) {
            result = min(result,tmp);
            left++;
        }
        else right++;
    }
    cout<< result;
    return 0;
}