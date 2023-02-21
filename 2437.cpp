#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
using namespace std;
int n, arr[1000];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    ll sum = 1;
    for(int i = 0; i < n; i++) {
        if(sum - arr[i] < 0) {
            cout << sum;
            break;
        }
        sum += arr[i];
    }
}
//1 1 2 3 6 7 30
//1 2 4 7 13 20