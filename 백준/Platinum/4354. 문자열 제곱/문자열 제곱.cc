#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main() {

    string S;
    while (1) {
        cin >> S;
        if (S == ".") break;
        int N = S.length();
        //prefix function
        int j=0;
        int p[N];
        memset(p,0,sizeof(p));

        for(int i=1; i<N; i++){
            while(j>0 && S[i] != S[j]){
                j = p[j-1]; 
            }
            if(S[i] == S[j]){
                j++;
                p[i] = j;
            }    
        }

        int pattern = N - p[N-1];
        
        if(N % pattern == 0) cout<< N/pattern <<endl;
        else cout<<1<<endl;
    }


    return 0;
}

