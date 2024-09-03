#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int T, n, m;
    cin >> T >> n;
    
    int A[1000];
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    cin >> m;
    int B[1000];
    for (int i = 0; i < m; i++) {
        cin >> B[i];
    }
    
    // A의 모든 부분 배열의 합 계산
    vector<int> sumA;
    for (int i = 0; i < n; i++) {
        int current_sum = 0;
        for (int j = i; j < n; j++) {
            current_sum += A[j];
            sumA.push_back(current_sum);
        }
    }

    // B의 모든 부분 배열의 합 계산
    vector<int> sumB;
    for (int i = 0; i < m; i++) {
        int current_sum = 0;
        for (int j = i; j < m; j++) {
            current_sum += B[j];
            sumB.push_back(current_sum);
        }
    }

    // sumA는 오름차순, sumB는 내림차순으로 정렬
    sort(sumA.begin(), sumA.end());
    sort(sumB.begin(), sumB.end(), greater<int>());

    long long count = 0;
    int i = 0, j = 0;

    // 투 포인터를 이용한 두 리스트의 합 비교
    while (i < sumA.size() && j < sumB.size()) {
        int a = sumA[i];
        int b = sumB[j];
        int sum = a + b;

        if (sum == T) {
            long long countA = 0;
            long long countB = 0;
            
            // sumA[i]와 같은 값의 개수를 모두 카운트
            while (i < sumA.size() && sumA[i] == a) {
                countA++;
                i++;
            }
            
            // sumB[j]와 같은 값의 개수를 모두 카운트
            while (j < sumB.size() && sumB[j] == b) {
                countB++;
                j++;
            }

            // 두 개수의 곱만큼 결과에 더하기 (쌍을 구하는 것 이므로 곱함)
            count += countA * countB;
        } else if (sum < T) {
            i++;
        } else {
            j++;
        }
    }

    cout << count;
    return 0;
}
