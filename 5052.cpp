#include <bits/stdc++.h>
using namespace std;
int n;
vector<string> number;
vector<<pair<int,int>> tree[10001];
bool comp_length(string s1, string s2) {
	return s1.size() < s2.size();
}
int main() {
	int tc; cin >> tc;
	while(tc--) {
		cin >> n;
		number.clear();
		for(int i = 0; i < n; i++) {
			string x; cin >> x;
			number.push_back(x);
		}
		sort(number.begin(),number.end(), comp_length);
		for(int i = 0; i < 5; i++) {
			cout << number[i] << "\n";
		}
		for(int i = 0; i < n; i++) {
			
		}
	}
}
