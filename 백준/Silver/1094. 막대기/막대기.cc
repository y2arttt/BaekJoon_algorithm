#include <iostream>

using namespace std;

int main() {
    int N = (1<<6);
    int wood = 0;
    int X;
    cin>>X;
    while (1)
    {
        
        if((N+wood) <=X) wood |= (N);
        if(wood == X) break;
        N = (N>>1);
    }
    int cnt = 0;
    while (wood > 0)
    {
        wood &= (wood-1);
        cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}