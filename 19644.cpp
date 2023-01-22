#include <bits/stdc++.h>
using namespace std;
int l, m, power, c;
int arr[3000001]; //arr[x] xm있는 좀비에게 입힐수 있는 damage;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> l >> m >> power >> c;
    for(int i = 1; i <= l; i++) {
        int x; cin >> x;
        int cur = arr[i - 1] - arr[max(0, i - m)];
        if(cur + power >= x) {
            arr[i] = arr[i - 1] + power;
            continue;
        }
        else {
            if(c) {
                c--;
                arr[i] = arr[i - 1];
            }
            else {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
}