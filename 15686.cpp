#include <bits/stdc++.h>
using namespace std;
int n, m, ans = 10000000;
int city[50][50];
int vis[13];
vector<pair<int,int>> selected;
vector<pair<int,int>> house;
vector<pair<int,int>> chick;
int getDist() {
	int dist = 0;
	for(int i = 0; i < house.size(); i++) {
		int min = 100000;
		for(int j = 0; j < m; j++) {
			auto cur = selected[j];
			int d = abs(house[i].first - cur.first) + abs(house[i].second - cur.second);
			if(min > d) min = d;
		}
		dist += min;
	}
	return dist;
}
void select(int num) {
	if(selected.size() == m) {
		int temp = getDist();
		if(temp < ans) ans = temp;
		return;
	}
	for(int i = num; i < chick.size(); i++) {
		selected.push_back(chick[i]);
		select(i + 1);
		selected.pop_back();
	}
}
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> city[i][j];
			if(city[i][j] == 1) {
				house.push_back({i,j});
			}
			else if(city[i][j] == 2) {
				chick.push_back({i,j});
			}
		}
	}
	select(0);
	cout << ans;
}
