#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
using namespace std;
int n, arr[50];
map<int, bool> vis;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    if(n == 1) {
        cout << 'A';
        return 0;
    }
    if(n == 2) {
        if(arr[0] == arr[1]) cout << arr[0];
        else cout << 'A';
        return 0;
    }
    int a = 123;
    if(arr[0] - arr[1]) a = (arr[1] - arr[2]) / (arr[0] - arr[1]);
    int b = arr[1] - arr[0] * a;
    for(int i = 0; i < n - 1; i++) {
        if(arr[i] * a + b != arr[i + 1]) {
            cout << 'B';
            return 0;
        }
    }
    cout << arr[n - 1] * a + b;
}