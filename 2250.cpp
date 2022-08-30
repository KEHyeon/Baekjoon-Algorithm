#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int n, root, col = 1, ans = 0, ansi = 1;
pair<int,int> tree[10001];
int node[10001];
int max_col[10001];
int min_col[10001];
void inorder(int cur, int level) {
	if(tree[cur].X != -1)  {
		inorder(tree[cur].X, level + 1);
	}
	max_col[level] = max(max_col[level], col);
	min_col[level] = min(min_col[level], col);
	col++;
	if(tree[cur].Y != -1) {
		inorder(tree[cur].Y, level + 1);
	}
}


int main() {
	cin >> n;
	for(int i = 0; i <= n; i++) {
		min_col[i] = 10000000;
	}
	for(int i = 0; i < n; i++) {
		int a, lc, rc;
		cin >> a >> lc >> rc;
		tree[a].X = lc;
		tree[a].Y = rc;
		if(lc!= -1)node[lc]++;
		if(rc!= -1)node[rc]++;
	}
	for(int i = 1; i <= n; i++) {
		if(node[i] == 0) {
			root = i;
			break;
		}
	}
	inorder(root, 1);
	for(int i = 2; i < col; i++) {
		if(ans < max_col[i] - min_col[i]) {
			ans = max_col[i] - min_col[i];
			ansi = i;
		}
	}
	cout << ansi << " " << ans + 1;
}
