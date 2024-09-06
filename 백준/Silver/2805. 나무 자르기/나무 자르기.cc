#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;
    long long m;
    int arr[1000000];
    
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int min=0,max=arr[n-1];
    while (max-min>1)
    {  
        int middle = (min+max)/2;
        long long cnt=0;
        for(int i=0; i<=n-1; i++){
            if(arr[i]-middle>0) cnt+= arr[i]-middle;
        }
        if(cnt == m) break;
        else if (cnt > m){
            min = middle;
        }
        else {
            max = middle;
        }
    }
    cout<<(min+max)/2;

    
    
    return 0;
}