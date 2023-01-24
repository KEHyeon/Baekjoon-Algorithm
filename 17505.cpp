#include <bits/stdc++.h>
using namespace std;
long long int n, k;
int main() {
    cin >> n >> k;
    bool flag = 0;
    long long int sum = 0;
    long long int cnt = 0;
    for(int i = 1; i < n; i++) {
        if(sum + (n - i) >= k)  {
            flag = 1;
            break;
        }
        sum += (n - i);
        cnt++;
    }
    if(!flag) {
        if(n == 1) {
            cout << 1;
        }
        else cout << -1;
        return 0;
    }
    int a;
    if(sum == 0) {
        a = k;
    }
    else a = k % sum;
    for(int i = n; i > n - cnt; i--) {
        cout << i << ' ';
    }
    for(int i = 1; i < n - cnt; i++) {
        if(n - cnt - i == a) cout << n - cnt << " ";
        cout << i << ' ';
    }
    if(k == 0) cout << n;
}