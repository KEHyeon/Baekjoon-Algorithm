#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int pi, k;
int memo[251][251][251];
int solve(int start, int people, int sum) {
    if(sum < 0 || start > pi) return 0;
    if(people == 0) return sum == 0;
    int &ret = memo[start][people][sum];
    if(ret != -1) return ret;
    ret = 0;
    for(int nxt = start; nxt * people <= sum; nxt++) {
        ret += solve(nxt, people - 1, sum - nxt);
    }
    return ret;
}
int main() {
    cin >> pi >> k;
    memset(memo, -1, sizeof(memo));
    cout << solve(1, k, pi);
}