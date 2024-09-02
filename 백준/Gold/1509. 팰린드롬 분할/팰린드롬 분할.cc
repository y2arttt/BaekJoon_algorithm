#include <iostream>
#include <vector>
#include <string>
#include <climits> 

using namespace std;

int main() {
    
    string s;
    cin >> s;
    int l = s.length();
    bool palindrome[2501][2501] = {false};
    for (int i = 0; i < l; i++) {
        palindrome[i][i] = true;  
    }

    for (int j = 1; j < l; j++) {
        for (int i = 0; i < j; i++) {
            if (s[i] == s[j]) {
                if (j - i == 1) {
                    palindrome[i][j] = true;  
                } else {
                    palindrome[i][j] = palindrome[i + 1][j - 1];  
                }
            }
        }
    }

    vector<int> ans(l, INT_MAX);  
    for (int j = 0; j < l; j++) {
        if (palindrome[0][j]) ans[j] = 1;  
        else {
            for (int i = 0; i < j; i++) {
                if (palindrome[i + 1][j]) ans[j] = min(ans[j], ans[i] + 1);  
            }
        }
    }
    
    cout << ans[l - 1]; 

    return 0;
}
