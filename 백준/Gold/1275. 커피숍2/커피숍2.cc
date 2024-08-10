#include <iostream>
#include <vector>

using namespace std;

vector<long long> tree(400001);
vector<int> numbers(100001);
long long build (int start,int end,int node){
    if(start == end){
        return tree[node] = numbers[start];
    }
    int mid = (start+end)/2;
    return tree[node] = build(start,mid,node*2) + build(mid+1,end,node*2+1);
}

void update (int start, int end, int index, int node, long long dif){
    if(start > index || end < index) return;
    tree[node] += dif;
    if(start == end) return;
    int mid = (start+end)/2;
    update(start,mid,index,node*2,dif);
    update(mid+1,end,index,node*2+1,dif);
}

long long query(int start,int end, int left,int right, int node){
    if(left<=start &&  end<=right) return tree[node];
    if(right < start || end < left) return 0;
    int mid = (start+end)/2;
    return query(start,mid,left,right,node*2) + query(mid+1,end,left,right,node*2+1);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); 
    
    int n,q;
    cin>>n>>q;
    for(int i=1; i<=n; i++){
        cin>>numbers[i];
    }
    build(1,n,1);
    for(int i=0; i<q; i++){
        int x,y,a,b;
        cin>>x>>y>>a>>b;
        if(x>y){
            int tmp = x;
            x = y;
            y = tmp;
        }
        cout<<query(1,n,x,y,1)<<'\n';
        update(1,n,a,1,b-numbers[a]);
        numbers[a] = b;
    }

    return 0;
}
