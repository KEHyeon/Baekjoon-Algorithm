#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
typedef pair<int,int> P;
int n, m;
int arr[2001][2001];
P parent[2001][2001];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};
int dx2[4] = {2,-2,0,0};
int dy2[4] = {0,0,-2,2};
void swap(P *a, P *b) {
	P temp = *a;
	*a = *b;
	*b = temp;
}
int cnt;
P Find(P node) {
	if(parent[node.X][node.Y].first < 0) return node;
	parent[node.X][node.Y] = Find(parent[node.X][node.Y]);
	return parent[node.X][node.Y];
}
void merge(P a,P b) {
	P para = Find(a);
	P parb = Find(b);
	if(para == parb) return;
	if(parent[para.X][para.Y] > parent[parb.X][parb.Y]) swap(a, b);
	parent[para.X][para.Y].first += parent[parb.X][parb.Y].first;
	parent[parb.X][parb.Y] = para; 
}
int main() {
	cin >> n >> m;
	cnt = m;
	queue<P> Q;
	for(int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		arr[a][b] = 1;
		Q.push({a, b});
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			parent[i][j].first = -1;
		}
	}
	while(!Q.empty()) {
		P cur = Q.front(); Q.pop();
		for(int i = 0; i < 4; i++) {
			int fx = cur.X + dx[i];
			int fy = cur.Y + dy[i];
			int fx2 = cur.X + dx2[i];
			int fy2 = cur.Y + dy2[i];
			if(fx < 1 || fy < 1 || fx > n || fy > n) continue;
			merge(cur,{fx,fy});
			if(!(fx2 < 1 || fy2 < 1 || fx2 > n || fy2 > n)) {
				if(arr[fx2][fy2]) {
					merge(cur, {fx2,fy2});
					P x = Find({fx,fy});
					if(parent[x.X][x.Y].first == -cnt){
						cout << max(arr[fx2][fy2], arr[fx][fy]);
						return 0;
					}
				}
			}
			else {
				P x = Find({fx,fy});
				if(parent[x.X][x.Y].first == -cnt){
					cout << arr[fx][fy];
					return 0;
				}
			}
			if(arr[fx][fy]) continue;
			arr[fx][fy] = arr[cur.X][cur.Y] + 1;;
			Q.push({fx,fy});
			cnt++;
		}
	}
}
