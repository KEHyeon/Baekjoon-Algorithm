#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
using namespace std;
int n, k;
vector<double> arr;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    arr.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    double ans1 = 0, ans2 = arr[k] * k + arr[n - k - 1] * k;
    for(int i = k; i < n - k; i++) {
        ans1 += arr[i];
        ans2 += arr[i];
    }
    printf("%.2lf\n%.2lf", ans1 / (n - k * 2) + 1e-8, ans2 / n + 1e-8);
}
