#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

long long *Tree;
long long *lazy;

void lazy_update(int Node, int start, int end){
    if(lazy[Node]%2==1){
        Tree[Node] = (end - start + 1) - Tree[Node];
    }
    if(start != end){
        lazy[Node * 2] += lazy[Node];
        lazy[Node * 2+1] += lazy[Node];
    }
    lazy[Node] = 0;

}

void range_update(int Node, int start, int end, int left, int right){
    lazy_update(Node, start, end);
    if(right < start || end < left) return;
    if(left <= start && end <= right){
        Tree[Node] = (end - start + 1) - Tree[Node];
        if(start != end){
            lazy[Node * 2] ++;
            lazy[Node * 2 + 1]++;
        }
        return;
    }
    int mid = (start + end) /2;
    range_update(Node * 2, start, mid, left,right);
    range_update(Node * 2+1, mid+1,end, left,right);
    Tree[Node] = Tree[Node * 2] + Tree[Node * 2 + 1];
    return;
}

int sum(int Node, int start, int end, int left, int right){
    lazy_update(Node, start, end);
    if(right < start || end < left) return 0;
    if(left <= start && end <= right) {
        return Tree[Node];
    }
    int mid = (start + end) /2;
    return sum(Node * 2, start, mid, left,right) + sum(Node * 2+1, mid+1,end, left,right);
}

int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N,M;
    cin>>N>>M;
    
    int height = ceil(log2(N));
    int tree_size = 1 << (height + 1);
    Tree = new long long [tree_size+4];
    lazy = new long long [tree_size+4];
    memset(lazy, 0, sizeof(long long) * tree_size);
    
    int O,S,T;
    while (M--){
        cin>>O>>S>>T;
        if(O==0){
            range_update(1,1,N,S,T);
        }
        else{
            cout<<sum(1,1,N,S,T)<<'\n';
        }
    }

    return 0;   
}