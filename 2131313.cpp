#include <bits/stdc++.h>

using namespace std;
int n;
int arr[100000];
int cnt[100000];
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    memset(cnt, 1000000, sizeof(cnt));
    cnt[0] = 0;
    for(int i = 1; i < n - 1; i++) {
        cnt[i + 1] = min(cnt[i + 1], cnt[i] + 1);
        if(i + arr[i] < n) cnt[i + arr[i]] = min(cnt[i + arr[i]], cnt[i] + 1);
    }
    cout << cnt[n - 1];
}