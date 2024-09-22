#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    int arr[100000];
    bool check[100001]{false};
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int end = 0;
    long long result = 0;
    for(int i=0; i<n; i++){
        while (end<n)
        {
            if(!check[arr[end]]){
                check[arr[end]] = true;
                end++;
            }
            else break;
        }
        result += (end - i);
        check[arr[i]] = false;
    }
    cout<<result;
    return 0;
}