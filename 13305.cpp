#include <bits/stdc++.h>

using namespace std;

long long int n, ans;
long long int city[100000];
long long int price[100000];

int main() {
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        cin >> price[i];

    }
    for(int i = 0; i < n; i++) {
        cin >> city[i];
    }
    long long int cur = city[0];
    for(int i = 0; i < n - 1; i++) {
        if(cur > city[i + 1]) {
            ans += cur * price[i];
            cur = city[i + 1];
        }
        else ans += cur * price[i];
    }
    cout << ans;
}
