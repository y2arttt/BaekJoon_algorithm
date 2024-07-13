#include <iostream>
#include <cmath>
using namespace std;

int N,K;
int words[50];
int base;
int maxCnt;

void dfs(int len, int check, int ing){
    if(len == 0){ //알파벳 조합 완성    
        int cnt = 0;
        for(int i = 0; i < N; i++){
            if((check & words[i]) == words[i]) cnt++;
        }
        if(maxCnt < cnt) maxCnt = cnt;
        return;
    }
    for(int i=ing; i<26; i++){
        if((check &(1<<i)) ==0 ){
            check |= (1<<i);
            dfs(len-1,check,i+1);
            check &= ~(1<<i);
        }   

    }
}


int main() {
    int tmp;
    string word;
    cin >>N>>K;
    for(int i = 0; i < N; i++){
        cin>>word;
        tmp = 0;
        for(char c : word){
            tmp |= (1 << (c - 'a'));
        }
        words[i] = tmp;
    }
    if(K < 5) cout<<0;
    else if(K == 26) cout<<N;
    else{
        base |= 1<<('a'-'a');
        base |= 1<<('n'-'a');
        base |= 1<<('t'-'a');
        base |= 1<<('i'-'a');
        base |= 1<<('c'-'a');
        dfs(K-5,base,0);
        cout<<maxCnt;
    }

    return 0;
}
