#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
using namespace std;
int arr[100001], n;
int memo[100000][5][5];
pii m[5] = {{1, 1}, {0, 1}, {1, 0}, {2, 1}, {1, 2}};
int dp(int num, int l, int r) {
    if(num == n) return 0;
    int &ret = memo[num][l][r];
    if(ret != 0) return ret;
    int cur = arr[num];
    float ld = sqrt((m[l].X - m[cur].X) * (m[l].X - m[cur].X) + (m[l].Y - m[cur].Y) * (m[l].Y - m[cur].Y));
    float rd = sqrt((m[r].X - m[cur].X) * (m[r].X - m[cur].X) + (m[r].Y - m[cur].Y) * (m[r].Y - m[cur].Y));
    int a, b;
    if(cur == l || cur == r) return ret = 1 + dp(num + 1, l, r);
    if(ld == 1) a = 2 + dp(num + 1, cur, r);
    else if(ld > 1 && ld < 2) a = 3 + dp(num + 1, cur, r);
    else a = 4 + dp(num + 1, cur, r);
    if(rd == 1) b = 2 + dp(num + 1, l, cur);
    else if(rd > 1 && rd < 2) b = 3 + dp(num + 1, l, cur);
    else b = 4 + dp(num + 1, l, cur);
    return ret = min(a, b);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while(1) {
        cin >> arr[n++];
        if(arr[n - 1] == 0) {
            n--;
            break;
        }
    }
    cout << dp(0, 0, 0);
}