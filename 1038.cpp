#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
using namespace std;
int n;
vector<int> arr;
bool ck(ll x) {
    int a = x;
    int l = x % 10; x /= 10;
    while(x != 0) {
        if(x % 10 <= l) return 0;
        l = x % 10; x /= 10;
    }
//    cout << a << "\n";
    return 1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    ll num = 0;
    for(int i = 0; i < n; i += ck(num++)) {
        if(num == 9876543210) {
            num = -1;
            break;
        }
    };
    cout << num;
}