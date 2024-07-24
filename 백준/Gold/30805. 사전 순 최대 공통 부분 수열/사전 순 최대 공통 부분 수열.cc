#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, M;
    
    cin >> N;
    int A[101];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    cin >> M;
    int B[101];
    for (int i = 0; i < M; i++) {
        cin >> B[i];
    }


    int Ai,Bi;
    int maxA=0, maxB=0;
    int cnt=0;
    int Sa = 0, Sb = 0;
    vector <int> result;
    while (true)
    {
        maxA = 0;
        maxB = 0;
        for(int i=Sa; i<N; i++){
            if(A[i] > maxA) {
                maxA = A[i];
                Ai = i;
            }
        }
        for(int i=Sb; i<M; i++){
            if(B[i] > maxB){
                maxB = B[i];
                Bi = i;
            }
        }
        
        if(maxA == 0 && maxB == 0) break;
        else if(A[Ai] > B[Bi]) {
            A[Ai] = 0;
            maxA=0;
        }
        else if(A[Ai] < B[Bi]){
            B[Bi] = 0;
            maxB=0;
        }
        else if(A[Ai] == B[Bi]){
            result.push_back(maxA);
            A[Ai] = 0;
            B[Bi] = 0;
            Sa = Ai + 1;
            Sb = Bi + 1;
            maxA = 0;
            maxB = 0;
            cnt++;
        }
    }
    cout<<cnt<<'\n';
    for(int r : result){
        cout<<r<<" ";
    }

    return 0;
}