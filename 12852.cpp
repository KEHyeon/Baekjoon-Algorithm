#include <bits/stdc++.h>
using namespace std;
int n, MAX = 123456789;
int memo[1000001];

int solve(int x) {
    if(x == 1) return 0;
    int &ret = memo[x];
    if(ret != 0) return ret;
    ret = MAX;
    if(x % 3 == 0) ret = min(ret, solve(x / 3) + 1);
    if(x % 2 == 0) ret = min(ret, solve(x / 2) + 1);
    ret = min(ret, solve(x - 1) + 1);
    return ret;
}
void tracking(int x) {
    if(x == 1) return;
    int ret = MAX, cur;
    if(x % 3 == 0 && ret > solve(x / 3)) {
        ret = solve(x / 3);
        cur = x / 3;
    }
    if(x % 2 == 0 && ret > solve(x / 2)) {
        ret = solve(x / 2);
        cur = x / 2;
    }
    if(ret > solve(x - 1)) {
        ret = solve(x - 1);
        cur = x - 1;
    }
    cout << cur << " ";
    tracking(cur);
}
int main () {
    cin >> n;
    cout << solve(n) << "\n";
    cout << n << " ";
    tracking(n);
}