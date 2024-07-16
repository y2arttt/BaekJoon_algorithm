#include <iostream>

using namespace std;

int main() {
    unsigned int N;
    cin >> N;
    int min = __builtin_ctz(N);
    int max = 32 - __builtin_clz(N);
    if(__builtin_popcount(N) == 1){
        cout<<(1<<(max-1))<<" "<<0<<endl;
    }
    else{
        cout<<(1<<max)<<" "<<max-min<<endl;
    }

    return 0;
}//제곱수 파악
