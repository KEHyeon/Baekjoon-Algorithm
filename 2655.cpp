#include <bits/stdc++.h>
using namespace std;
int n, memo[101];
tuple<int,int,int> brick[101];
vector<int> ans;
int dp(int top) {
    int &ret = memo[top];
    if(ret != 0) return ret;
    int area, high, heavy;
    tie(area, high, heavy) = brick[top];
    ret = high;
    for(int i = 0; i < n; i++) {
        int nxtArea, nxtHigh, nxtHeavy;
        tie(nxtArea, nxtHigh, nxtHeavy) = brick[i];
        if(nxtArea <= area || nxtHeavy <= heavy) continue;
        ret = max(ret, high + dp(i));
    }
    return ret;
}
void tracking(int top) {
    int area, high, heavy;
    tie(area, high, heavy) = brick[top];
    int nxtMax = 0;
    int nxtBrick;
    for(int i = 0; i < n; i++) {
        int nxtArea, nxtHigh, nxtHeavy;
        tie(nxtArea, nxtHigh, nxtHeavy) = brick[i];
        if(nxtArea <= area || nxtHeavy <= heavy) continue;
        if(nxtMax < dp(i)) {
            nxtMax = dp(i);
            nxtBrick = i;
        }
    }
    if(nxtMax == 0) return;
    ans.push_back(nxtBrick);
    tracking(nxtBrick);
}
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a, b, c; cin >> a >> b >> c;
        brick[i] = {a, b, c};
    }
    tracking(n + 1);
    cout << ans.size() << "\n";
    for(int i : ans) cout << i + 1 << "\n";
}