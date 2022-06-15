#include <bits/stdc++.h>
using namespace std;
int n;
pair<int,int> arr[100000];
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i].second >> arr[i].first;
    sort(arr, arr + n);
    int cnt = 1;
    int cur = 0;
    for(int i = 1; i < n; i++) {
        if(arr[cur].first <= arr[i].second) {
            cur = i;
            cnt++;
        }
    }
    cout << cnt;
}