#include <iostream>
#include <cstring>


using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;
    cin>>n;
    int seq[2000];
    for(int i=0; i<n; i++){
        cin>>seq[i];
    }
    bool palindrome[2000][2000];
    memset(palindrome, false, sizeof(palindrome));
    for(int j=0; j<n; j++){
        for(int i=0; i<=j; i++){
            if(j==i){
                palindrome[i][j]=true;
            }
            else if(seq[i] == seq[j]){
                if(j-i == 1) palindrome[i][j] = true;
                else if(palindrome[i+1][j-1] == true) palindrome[i][j] = true;
            }
        }
    }

    int m;
    cin>>m;
    for(int i=0; i<m; i++){
        int s,e;
        cin>>s>>e;
        cout << (palindrome[s-1][e-1] ? 1 : 0) << '\n';
    }

    return 0;
}
