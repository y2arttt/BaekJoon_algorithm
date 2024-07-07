#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if(__builtin_popcount(n) == 1){
        cout<<1<<endl;
    }
    else{
        cout<<0<<endl;
    }

    return 0;
}