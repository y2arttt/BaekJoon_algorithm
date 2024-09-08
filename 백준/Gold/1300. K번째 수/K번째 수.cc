#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, k;
	cin >> n >> k;

	int lt = 1, rt = k, mid, cnt;

	while (lt <= rt) {
		mid = (lt + rt) / 2;
		cnt = 0;

		for (int i = 1; i <= n; i++) {
			cnt += min(n, mid / i);
		}

		if (cnt >= k) rt = mid - 1;
		else lt = mid + 1;
	}

	cout << lt;
	return 0;
}