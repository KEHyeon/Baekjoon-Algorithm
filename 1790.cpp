#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, k;

int main() {
    cin >> n >> k;
    ll len = 1;
    ll a = 9;
    while(k - a * len > 0) {
        k -= a * len;
        a *= 10;
        len++;
    }
    ll num = 1;
    for(int i = 0; i < len - 1; i++) num *= 10;
    num =  num + k / len - 1;
    if(num + (k % len != 0) > n) {
        cout << -1;
        return 0;
    }
    if(k % len == 0) cout << num % 10;
    else {
        num++;
        int cnt = 0;
        while(len - cnt >= k % len) {
            if(len - cnt == k % len) {
                cout << num % 10;
                return 0;
            }
            num /= 10;
            cnt++;
        }
    }
}