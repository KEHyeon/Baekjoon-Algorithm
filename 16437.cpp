#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<int> tree[123457];
ll how[123457];
char who[1234567];
ll dfs(int cur) {
	ll s_count = 0LL;
	for(int nxt : tree[cur]) {
		s_count += dfs(nxt);
	}
	if(who[cur] == 'S') return s_count + how[cur];
	else return max(s_count - how[cur], 0LL);
}
int main() {
	cin >> n;
	who[1] = 'S';
	for(int i = 2; i <= n; i++) {
		char t;
		ll a, p;
		cin >> t >> a >> p;
		tree[p].push_back(i);
		who[i] = t;
		how[i] = a;
	}
	cout << dfs(1);
}
