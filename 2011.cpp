#include <bits/stdc++.h>
using namespace std;
string str;
int dp[5001];
int main() {
	cin >> str;
	int len = str.size();
	if(str[0] == '0') {
			cout << 0;
			return 0;
	}
	dp[0] = 1;
	for(int i = 1; i < len; i++) {
		if((str[i] <= '6' && str[i - 1] == '2') || str[i - 1] == '1') {
			if(i == 1) dp[i] = 1;
			else dp[i] = dp[i - 2];
		}
		if(str[i] != '0') dp[i] = (dp[i] + dp[i - 1]) % 1000000; 
	}
	cout << dp[len - 1];
}
