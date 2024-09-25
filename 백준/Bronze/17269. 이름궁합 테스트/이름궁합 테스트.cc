#include <iostream>
using namespace std;

int mix[200];

void dp(int &k) {
    while (k > 2) {  
        for (int i = 0; i < k - 1; i++) mix[i] = (mix[i] + mix[i + 1]) % 10;  
        k--; 
    }
}

int main() {
    int check[26] = {3, 2, 1, 2, 4, 3, 1, 3, 1, 1, 3, 1, 3, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};
    int n, m;
    cin >> n >> m;
    char word1[100];
    char word2[100];

    for (int i = 0; i < n; i++) {
        cin >> word1[i];  
    }
    for (int j = 0; j < m; j++) {
        cin >> word2[j]; 
    }

    int i = 0, j = 0;
    int k = 0;
    while (i < n || j < m) {
        if (i < n) mix[k++] = check[word1[i++] - 'A'];  
        if (j < m) mix[k++] = check[word2[j++] - 'A'];  
    }

    dp(k);
    if(mix[0] == 0)cout << mix[1] << "%";
    else cout << mix[0] << mix[1] << "%";

    return 0;
}
