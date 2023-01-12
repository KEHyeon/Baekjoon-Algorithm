#include <bits/stdc++.h>
using namespace std;

int n;
int arr[5001];

int main() {
    cin >> n;
    for(int i = 0; i < n * 2; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + (n * 2));
    int s = 0;
    int e = n * 2 - 1;
    int ans = 123456789;
    while(s < e) {
        ans = min(ans, arr[s] + arr[e]);
        s++;
        e--;
    }
    cout << ans;
}