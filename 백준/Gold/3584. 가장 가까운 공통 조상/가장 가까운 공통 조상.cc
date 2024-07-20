#include <iostream>
#include <cstring>
using namespace std;

int getDepth(int node, int Node[]) {
    int depth = 0;
    while (node != 0) {
        depth++;
        node = Node[node];
    }
    return depth;
}

int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int Node[100001];
    bool check[100001];
    int T,n,parent,child;
    int current1,current2;
    
    cin>>T;
    for(int i=0; i<T; i++){
        memset(Node,0,sizeof(Node));
        memset(check,false,sizeof(check));
        cin>>n;
        for(int j=0;j<n-1;j++){
            cin>>parent>>child;
            Node[child] = parent;
        }
        cin>>current1>>current2;
        int depth1=getDepth(current1,Node), depth2=getDepth(current2,Node);
        
        while (depth1 > depth2)
        {
            current1 = Node[current1];
            depth1 --;
        }
        while (depth1 < depth2)
        {
            current2 = Node[current2];
            depth2 --;
        }

        while (current1 != current2) {
            current1 = Node[current1];
            current2 = Node[current2];
        }
        
        cout << current1 << "\n";
    }

    return 0;
}
