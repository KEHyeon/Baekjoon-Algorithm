#include <bits/stdc++.h>
using namespace std;
bool ck[4000001];
vector<int> prime;
int n;
int main() {
    cin >> n;
    if(n == 1) {
        cout << 0;
        return 0;
    }
    ck[2] = 0;
    for(int i = 2; i <= n; i++) {
        if(!ck[i]) {
            prime.push_back(i);
            for(int j = i * 2; j <= n; j += i) {
                ck[j] = 1;
            }
        }
    }
    int s = 0, e = 0, ans = 0;
    int sum = prime[0];
    while(s <= e && e < prime.size()) {
        if(sum < n) {
            e++;
            sum += prime[e];
        }
        else {
            ans += (sum == n);
            sum -= prime[s];
            s++;
        }
    }
    cout << ans;
}