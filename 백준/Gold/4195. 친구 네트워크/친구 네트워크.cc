#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

unordered_map<string, string> um;
unordered_map<string, int> friends;

string find(string a){
    if(um[a]==a) return a;
    else{
        return um[a] = find(um[a]);
    }
}

void uni(string a, string b){
    string A = find(a);
    string B = find(b);
    if(A == B) return;
    um[B] = A;
    friends[A]+=friends[B];
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    
    int t;
    cin >> t;
    while (t--) {
        int f;
        cin >> f;
        um.clear();
        friends.clear();    
        for (int i = 0; i < f; i++) {
            string a, b;
            cin >> a >> b;
            if(um.count(a) == 0){
                um.insert({a,a});
                friends.insert({a,1});
            }
            if(um.count(b) == 0){
                um.insert({b,b});
                friends.insert({b,1});
            }
            uni(a,b);
            cout<<friends[find(a)]<<'\n';
        }
    }
    


    return 0;
}
