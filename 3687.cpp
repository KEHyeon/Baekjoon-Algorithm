#include <bits/stdc++.h>
using namespace std;
int n;
int matches[8] = {0, 0, 1, 7, 4, 2, 0, 8};
long long int memo[101];
long long int getMin(int x) {
    if(x < 2) return 1844674407370955165;
    if(x <= 7) {
        if(x == 6) return 6;
        return matches[x];
    }
    long long int &ret = memo[x];
    if(ret != 0) return ret;
    ret = 1844674407370951615;
    for(int i = 2; i <= 7; i++) {
        long long int temp;
        if(ret > getMin(x - i) * 10 + matches[i]) {
            ret = getMin(x - i) * 10 + matches[i];
        }
    }
    return ret;
}
int main() {
    int tc; cin >> tc;
    while(tc--) {
        cin >> n;
        cout << getMin(n) << " ";
        if(n % 2) {
            cout << 7;
            n -= 3;
        }
        for(int i = 0; i < n / 2; i++) cout << '1';
        cout << '\n';
    }
}