#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

long long *tree;
long long *lazy;
long long arr[1000001];


long long build(int node, int start, int end) {
    if (start == end) {
        return tree[node] = arr[start];
    }
    int mid = (start + end) / 2;
    return tree[node] = build(node * 2, start, mid) + build(node * 2 + 1, mid + 1, end);
}
void lazy_update(int node, int start, int end) {
    if (lazy[node] != 0) {
        tree[node] += (end - start + 1) * lazy[node];
        if (start != end) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}


void range_update(int node, int start, int end, int left, int right, long long diff) {
    lazy_update(node, start, end);
    
    if (left > end || right < start) return;
    
    if (left <= start && end <= right) {
        tree[node] += (end - start + 1) * diff;
        if (start != end) {
            lazy[node * 2] += diff;
            lazy[node * 2 + 1] += diff;
        }
        return;
    }
    
    int mid = (start + end) / 2;
    range_update(node * 2, start, mid, left, right, diff);
    range_update(node * 2 + 1, mid + 1, end, left, right, diff);
    
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

long long query(int node, int start, int end, int left, int right) {
    lazy_update(node, start, end);
    
    if (left > end || right < start) return 0;
    
    if (left <= start && end <= right) return tree[node];
    
    int mid = (start + end) / 2;
    return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;

    int height = ceil(log2(N));
    int tree_size = 1 << (height + 1);
    tree = new long long[tree_size];
    lazy = new long long[tree_size];
    memset(lazy, 0, sizeof(long long) * tree_size);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    build(1, 0, N - 1);

    for (int i = 0; i < M + K; i++) {
        int a;
        cin >> a;

        if (a == 1) {
            int b, c;
            long long d;
            cin >> b >> c >> d;
            range_update(1, 0, N - 1, b - 1, c - 1, d);
        } else {
            int b, c;
            cin >> b >> c;
            cout << query(1, 0, N - 1, b - 1, c - 1) << '\n';
        }
    }

    return 0;
}