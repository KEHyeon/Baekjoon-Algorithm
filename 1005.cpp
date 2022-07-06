#include <bits/stdc++.h>
using namespace std;
int main() {
	int tc; cin >> tc;
	while(tc--) {
		int n, k; cin >> n >> k;
		vector<int> graph[n + 1];
		int time[n + 1];
		bool isUsed[n + 1] = {0,};
		int indegree[n + 1] = {0,};
		int dp[n + 1] = {0,};
		queue<int> q;
		for(int i = 1; i <= n; i++) cin >> time[i];
		while(k--) {
			int a, b; cin >> a >> b;
			graph[a].push_back(b);
			indegree[b]++;
		}
		for(int i = 1; i <= n; i++) {
			if(indegree[i] == 0) q.push(i);
		}
		while(!q.empty()) {
			int cur = q.front(); q.pop();
			dp[cur] += time[cur];
			for(auto nxt : graph[cur]) {
				if(isUsed[nxt]) {
					dp[nxt] = max(dp[nxt], dp[cur]);
				}
				else {
					dp[nxt] = dp[cur];
					isUsed[nxt] = 1;
				}
				indegree[nxt]-=1;
				if(indegree[nxt] == 0) q.push(nxt);
			}
		}
		int w; cin >> w;
		cout << dp[w] << "\n";
	}
}
