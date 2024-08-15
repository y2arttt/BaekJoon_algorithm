#include <iostream>
#include <vector>
using namespace std;
vector<int> inorder;
vector<int> postorder;
int indx[100001];
void preorder(int inS, int inE, int poS, int poE)
{
	if (inS > inE || poS > poE) return;

	int root = postorder[poE];
	int rootindx = indx[root];//중위순회 루트 index찾기
	int leftSize = rootindx - inS;//중위순회 루트 기준 left
	int rightSize = inE - rootindx; //중위순회 루트 기준 right

	cout << root << " ";

	preorder(inS, rootindx-1, poS, poS + leftSize-1);
	preorder(rootindx + 1, inE, poS + leftSize, poE - 1);
}

int main(void)
{
    int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;
		inorder.push_back(n);
		indx[n] = i; // 빠른 indx 찾기 위해 -> 시간복잡도 줄이기
	}
	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;
		postorder.push_back(n);
	}
	preorder(0,N-1,0,N-1);

}