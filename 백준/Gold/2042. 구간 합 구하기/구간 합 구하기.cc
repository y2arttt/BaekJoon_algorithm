#include <iostream>
#include <cmath>

using namespace std;

long long *tree;
long long datas[1000001];

long long build(int start, int end, int Node){
    if(start == end){ //구간이 1이면
        return tree[Node] = datas[start];
    }
    int mid = (start + end) / 2; // 구간의 반을 나눔
    return tree[Node] = build(start,mid,Node*2) + build(mid+1,end,(Node*2)+1);
}

long long sum (int start, int end, int startdata, int enddata, int Node){
    if(start > enddata || end < startdata) return 0; //범위 밖으로 나감
    if(start >= startdata && end <= enddata) return tree[Node]; //범위 안으로 들어옴
    //범위에 걸침
    int mid = (start + end)/2;
    return sum(start,mid,startdata,enddata,Node*2) + sum(mid+1,end,startdata,enddata,Node*2+1);
}

void update(int start, int end,int Node, int index, long long dif){
    if(start > index || index > end) return;
    tree[Node] += dif;
    if(start == end) return;
    int mid = (start + end)/2;
    update(start,mid,Node * 2, index, dif);
    update(mid+1,end,Node * 2 +1, index, dif);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N,M,K;
    cin>>N>>M>>K;
    int height = ceil(log2(N));//높이 구하기 (log를 올림함)
    tree = new long long[1<<(height+1)];
    for(int i=0;i<N;i++){
        cin>>datas[i];
    }
    build(0, N - 1, 1); 
    long long a,b,c;
    for(int i=0; i<M+K; i++){
        cin>>a>>b>>c;
        if(a == 1){ //a ==1이라면 b를 c로 바꿈
            long long dif = c - datas[b-1];
            datas[b-1] = c;
            update(0,N-1,1,b-1,dif);
        }
        else{
            cout<<sum(0,N-1,b-1,c-1,1)<<'\n';
        }
    }
    return 0;
}