#include <bits/stdc++.h>
using namespace std;

int main() {
	string str; cin >> str;
	string boom; cin >> boom;
	int len = str.size();
	int blen = boom.size();
	string ans = "";
	for(int i = 0; i < len; i++) {
		ans += str[i];
		if(str[i] == boom[blen - 1] && ans.size() >= blen) {
			int flag = 1;
			int cnt = ans.size() - 1;
			for(int j = blen - 1; j >= 0; j--) {
				if(boom[j] != ans[cnt--]) {
					flag = 0;
					break;
				}
			}
			if(flag) {
				for(int j = 0; j < blen; j++) {
					ans.pop_back();
				}
				continue;
			}
		}
	}
	if(ans.size() == 0) cout << "FRULA";
	else cout << ans;
}
