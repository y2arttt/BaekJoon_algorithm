#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    vector<int> numbers(N);
    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }

    sort(numbers.begin(), numbers.end());

    int goodCount = 0;
    for (int i = 0; i < N; i++) {
        int left = 0, right = N - 1;
        while (left < right) {
            if (left == i) {
                left++;
                continue;
            }
            if (right == i) {
                right--;
                continue;
            }

            int sum = numbers[left] + numbers[right];
            if (sum == numbers[i]) {
                goodCount++;
                break;
            } else if (sum < numbers[i]) {
                left++;
            } else {
                right--;
            }
        }
    }

    cout << goodCount << endl;
    return 0;
}