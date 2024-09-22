#include <iostream>
#include <algorithm>
using namespace std;
int arr[3000000];
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    int n,d,k,c;
    cin>>n>>d>>k>>c;
    
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int check[3001]={0};
    int result = 0;
    int over = 0;
    for(int i=0; i<k; i++){
        if(check[arr[i]] != 0) over++; 
        check[arr[i]] ++;
    }
    int coupon = (check[c] == 0 ? 1 : 0);
    result = max(result,k-over + coupon);
    for(int i=1; i<n; i++){
        check[arr[i-1]]--;
        if(check[arr[i-1]] != 0) over--;
        // 새 접시
        if(check[arr[(i+k-1)%n]] != 0) over++; 
        check[arr[(i+k-1) % n]]++;
        coupon = (check[c] == 0 ? 1 : 0);
        result = max(result,k - over + coupon);
    }
    cout<<result;
    return 0;
}