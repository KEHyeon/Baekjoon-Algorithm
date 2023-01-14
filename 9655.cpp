#include <bits/stdc++.h>
using namespace std;
int n;
bool memo[1001] = {0, 1, 0, 1};
int main() {
    cin >> n;
    for(int i = 4; i <= n; i++) {
        memo[i] = !(memo[i - 3] && memo[i - 1]);
        cout << memo[i] << '\n';
    }
    if(memo[n]) cout << "SK";
    else cout << "CY";
}