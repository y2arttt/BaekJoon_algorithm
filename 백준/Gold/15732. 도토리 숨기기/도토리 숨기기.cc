#include <iostream>
#include <vector>
using namespace std;

struct rule
{
	int s,e,j;
	rule(int s,int e, int j):s(s),e(e),j(j){};
};


int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    int result;
    int n, k;
	int d;
    cin>>n>>k>>d;
    int s=0,&e=n;
    vector <rule> rule;
    for(int i=0; i<k; i++){
        int a,b,c;
        cin>>a>>b>>c;
        rule.push_back({a,b,c});
    }
    while (s<=e)
    {
        long long cnt=0;
        int m = (s+e)/2;
        for(auto&r : rule){
            if(m < r.s) continue;
			cnt += (min(m,r.e)-r.s)/r.j + 1;
        }
        if(cnt<d){
            s=m+1;
        }
        else{
			result=m;
            e=m-1;
        }
    }
    cout<<result;
    
    return 0;
}
