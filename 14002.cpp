#include <bits/stdc++.h>
using namespace std;
int n, ans;
int arr[1000];
int memo[1000];
int getLen(int start) {
    if(start == n) return 0;
    int &ret = memo[start];
    if(ret != 0) return ret;
    ret = 1;
    for(int i = start + 1; i < n; i++) {
        if(arr[start] < arr[i]) {
            ret = max(ret, getLen(i) + 1);
        }
    }
    return ret;
}
void print(int start) {
    if(start == n) return;
    int maxStart = -1;
    int maxLen = 0;
    for(int i = start + 1; i < n; i++) {
        if(maxLen < getLen(i) && arr[start] < arr[i]) {
            maxLen = getLen(i);
            maxStart = i;
        }
    }
    if(maxStart == -1) return;
    cout << arr[maxStart] << " ";
    print(maxStart);
}
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    int start;
    for(int i = 0; i < n; i++) {
        if(getLen(i) > ans) {
            start = i;
            ans = getLen(i);
        }
    }
    cout << ans << "\n";
    cout << arr[start] << " ";
    print(start);
}
