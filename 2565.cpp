#include <bits/stdc++.h>

using namespace std;
int a[501], b[501], alen, blen;
int lis(int *arr, int len) {
    int lis[501] = {0,};
    int num = 0;
    for(int i = 1; i <= len; i++) {
        if(arr[i] == 0) continue;
        lis[i] = 1;
        for(int j = 1; j < i; j++) {
            if(arr[i] > arr[j] && arr[i] != 0) {
                lis[i] = max(lis[i], lis[j] + 1);
                num = max(num, lis[i]);
            }
        }
    }
    return num;
}
int main() {
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        a[x] = y; b[y] = x;
        alen = max(alen, x);
        blen = max(blen, y);
    }
    cout << n - lis(a, alen);
}