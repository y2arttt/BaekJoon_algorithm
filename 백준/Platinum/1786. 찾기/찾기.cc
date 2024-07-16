#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

int main() {

    string T,P;
    vector <int> matches;

    getline(cin,T);
    getline(cin,P);
    int N = P.length();
    //prefix function
    int j=0;
    int pattern[N];
    memset(pattern,0,sizeof(pattern));

    for(int i=1; i<N; i++){
        while(j>0 && P[i] != P[j]){
            j = pattern[j-1]; 
        }
        if(P[i] == P[j]){
            j++;
            pattern[i] = j;
        }    
    }
    //KMP
    int M = T.size();
    j = 0;
    for(int i=0; i<M; i++){
        while (j > 0 && T[i] != P[j])
        {
            j = pattern[j-1];
        }
        
        if(T[i] == P[j]) {
            if (j == N - 1) {
                matches.push_back(i - N + 1);
                j = pattern[j];
            } else {
                j++;
            }
        }
    }
    cout<<matches.size()<<endl;
    for(auto result : matches) {
        cout<<result + 1<<" ";
    }

    return 0;
}

