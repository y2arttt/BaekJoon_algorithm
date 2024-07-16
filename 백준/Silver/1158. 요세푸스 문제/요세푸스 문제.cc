#include <iostream>
#include <list>

using namespace std;


int main()
{

    list<int> li;
    list<int>::iterator iter;
    int N,K;
    cin>>N>>K;
    for(int i=1; i<=N; i++){
        li.push_back(i);
    }
    iter = li.begin();
    cout<<"<";
    while(!li.empty()){
        for(int i=0; i<K-1; i++){
            iter++;
            if(iter == li.end()){
                iter = li.begin();
            }
        }
        cout<<*iter;
        iter = li.erase(iter);
        if(iter == li.end()){
            iter = li.begin();
        }
        if(li.empty()) cout<<">";
        else cout<<", ";
    }

    return 0;
}
