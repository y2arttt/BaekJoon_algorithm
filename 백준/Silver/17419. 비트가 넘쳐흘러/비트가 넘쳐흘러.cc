#include <iostream>
#include <string>

using namespace std;

int main() {
    int N;
    string binary;
    unsigned long long K = 0;
    int count = 0;      

    cin >> N>> binary;

    for (char c : binary) {
        if(c == '1') count++;
    }

    cout << count << endl;

    return 0;
}