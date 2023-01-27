#include <bits/stdc++.h>
using namespace std;
int n, l, r, x;
vector<int> now;
int isUsed[15];
int problems[15];
int bt(int num) {
    int sum = 0;
    int maxNum = -1;
    int minNum = INT_MAX;
    for(auto i : now) {
        sum += i;
        maxNum = max(maxNum, i);
        minNum = min(minNum, i);
    }
    int cnt = sum >= l && sum <= r && maxNum - minNum >= x;
    for(int i = num; i < n; i++) {
        if(isUsed[i]) continue;
        isUsed[i] = 1;
        now.push_back(problems[i]);
        cnt += bt(i + 1);
        isUsed[i] = 0;
        now.pop_back();
    }
    return cnt;
}
int main() {
    cin >> n >> l >> r >> x;
    for(int i = 0; i < n; i++) {
        cin >> problems[i];
    }
    cout << bt(0);
}