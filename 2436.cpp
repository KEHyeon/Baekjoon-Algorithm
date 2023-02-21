#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
using namespace std;
int a, b;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> a >> b;
    int ans1 = 0, ans2 = INT_MAX;
    int aa = INT_MAX;
    for(int i = 1; i <= b; i++) {
        if(b % i == 0 && gcd(a*i, b / i) == a && abs(a*i - b/i) < aa) {
            aa = abs(a*i - b/i);
            ans1 = a * i;
            ans2 = b / i;
        }
    }
    if(ans1 > ans2) swap(ans1, ans2);
    cout << ans1 << " " << ans2;
}