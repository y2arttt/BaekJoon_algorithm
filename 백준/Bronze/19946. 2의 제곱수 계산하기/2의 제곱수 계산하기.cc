#include <iostream>

using namespace std;

int main()
{
    unsigned long long n;
    cin >> n;
    cout << __builtin_popcountll(n);

    return 0;
}