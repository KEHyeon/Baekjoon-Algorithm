#include <bits/stdc++.h>
using namespace std;
int n, m;
int memo[201][201];
const int mod = 1000000000;
int f(int k, int sum) {
    if(k == 0 || sum < 0) {
        return sum == 0;
    }
    int &ret = memo[k][sum];
    if(ret != -1) return ret;
    ret = 0;
    for(int i = 0; i <= n; i++) {
        ret = (ret + f(k - 1, sum - i)) % mod;
    }
    return ret;
}
int main() {
	cin >> n >> m;
    memset(memo, -1, sizeof(memo));
	cout << f(m, n);
}
