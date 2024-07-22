#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

struct Node {
    long long sum;
    long long lazy;
    long long lazyDiff;
};

Node *tree;
long long datas[100001];

void lazy_update(int node, int start, int end) {
    if (tree[node].lazy != 0 || tree[node].lazyDiff != 0) {
        tree[node].sum += (end - start + 1) * tree[node].lazy + (end - start + 1) * (end - start) / 2 * tree[node].lazyDiff;
        if (start != end) {
            int mid = (start + end) / 2;
            tree[node*2].lazy += tree[node].lazy;
            tree[node*2].lazyDiff += tree[node].lazyDiff;
            tree[node*2+1].lazy += tree[node].lazy + (mid - start + 1) * tree[node].lazyDiff;
            tree[node*2+1].lazyDiff += tree[node].lazyDiff;
        }
        tree[node].lazy = tree[node].lazyDiff = 0;
    }
}

void range_update(int node, int start, int end, int left, int right) {
    lazy_update(node, start, end);
    if (left > end || right < start) return;
    if (left <= start && end <= right) {
        tree[node].lazy += start - left + 1;
        tree[node].lazyDiff += 1;
        lazy_update(node, start, end);
        return;
    }
    int mid = (start + end) / 2;
    range_update(node*2, start, mid, left, right);
    range_update(node*2+1, mid+1, end, left, right);
    tree[node].sum = tree[node*2].sum + tree[node*2+1].sum;
}

long long query(int node, int start, int end, int idx) {
    lazy_update(node, start, end);
    if (idx < start || idx > end) return 0;
    if (start == end) return tree[node].sum;
    int mid = (start + end) / 2;
    if (idx <= mid) return query(node*2, start, mid, idx);
    else return query(node*2+1, mid+1, end, idx);
}

void build(int node, int start, int end) {
    if (start == end) {
        tree[node].sum = datas[start];
        return;
    }
    int mid = (start + end) / 2;
    build(node*2, start, mid);
    build(node*2+1, mid+1, end);
    tree[node].sum = tree[node*2].sum + tree[node*2+1].sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, Q;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> datas[i];
    }

    int tree_size = 1 << ((int)ceil(log2(N)) + 1);
    tree = new Node[tree_size]();

    build(1, 1, N);

    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int L, R;
            cin >> L >> R;
            range_update(1, 1, N, L, R);
        } else {
            int X;
            cin >> X;
            cout << query(1, 1, N, X) << '\n';
        }
    }

    delete[] tree;
    return 0;
}