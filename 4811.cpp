#include <bits/stdc++.h>
using namespace std;
int n;
long long memo[31][31];
long long solve(int one, int half) {
    if(one == 0) return 1;
    long long &ret = memo[one][half];
    if(ret != 0) return ret;
    ret += solve(one - 1, half + 1);
    ret += half != 0 ? solve(one, half - 1) : 0;
    return ret;
}
int main() {
    cin >> n;
    while(n) {
        cout << solve(n, 0) << "\n";
        cin >> n;
    }
}