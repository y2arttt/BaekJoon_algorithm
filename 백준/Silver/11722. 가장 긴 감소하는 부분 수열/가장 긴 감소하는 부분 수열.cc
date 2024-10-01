#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int arr[1000];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	vector<int> seq;
	seq.push_back(arr[0]);
	for(int i=1; i<n; i++){
		int l=0,r = seq.size() - 1;
		while (l<=r){
			int mid=(l+r)/2;
			if(seq[mid] > arr[i]){
				l = mid + 1;
			}
			else{
				r = mid - 1;
			}
		}
		if(l == seq.size()) seq.push_back(arr[i]);
		else seq[l]=arr[i];
			
	}
	cout<<seq.size();
	return 0;
}