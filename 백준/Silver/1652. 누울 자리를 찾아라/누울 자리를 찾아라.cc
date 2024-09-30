#include<iostream>
using namespace std;

int main()
{
	int n;
	char arr[100][100];
	cin>>n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>arr[i][j];
		}
	}
	int x=0;
	for(int i=0; i<n; i++){
		int cons = 0;
		for(int j=0; j<n; j++){
			if(arr[i][j] == '.'){
				cons++;
			}
			else {
				if(cons >= 2) x++;
				cons = 0;
			}
		}
		if(cons >= 2) x++;
	}
	int y=0;
	for(int i=0; i<n; i++){
		int cons = 0;
		for(int j=0; j<n; j++){
			if(arr[j][i] == '.'){
				cons++;
			}
			else {
				if(cons >= 2) y++;
				cons = 0;
			}
		}
		if(cons >= 2) y++;
	}
	cout<<x<<" "<<y;
}