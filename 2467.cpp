#include <bits/stdc++.h>
using namespace std;
int n;
int arr[100001];
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    int s = 0;
    int e = n - 1;
    int MIN = abs(arr[s] + arr[e]);
    int ans1 = s;
    int ans2 = e;
    while(s < e) {
        if(abs(arr[s] + arr[e]) <= MIN) {
            ans1 = s;
            ans2 = e;
            MIN = abs(arr[s] + arr[e]);
        }
        if(arr[s] + arr[e] < 0) s++;
        else e--;
    }
    cout << arr[ans1] << " " << arr[ans2];
}