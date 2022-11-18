#include <bits/stdc++.h>
using namespace std;
int n;
int MIN = -1000000000;
int arr[100000];
int memo[100000][2], ans = MIN;
int solve(int start, int removed) {
    if(removed == 2) return MIN;
    if(removed == 3) return 0;
    if(start == n) return 0;
    int &ret = memo[start][removed];
    if(ret != MIN) return ret;
    ret = max(arr[start] + solve(start + 1, removed), solve(start + 1, removed + 1));
    ret = max(0, ret);
    return ret;
}
int main() {
    cin >> n;
    bool flag = 1;
    int maxnum = -10000000;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        if(arr[i] > 0) flag = 0;
        maxnum = max(maxnum, arr[i]);
    }
    if(flag) {
        cout << maxnum;
        return 0;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 2; j++) {
            memo[i][j] = MIN;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 2; j++) {
            ans = max(ans, solve(i, j));
        }
    }
    cout << ans;
}