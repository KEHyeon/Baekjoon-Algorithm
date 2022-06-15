#include <bits/stdc++.h>
using namespace std;
int n, sum, ans;
int arr[20];
void f(int num, int b) {
    if(sum == b) {
        ans++;
    }
    for(int i = num + 1; i < n; i++) {
        f(i ,b + arr[i]);
    }
}
int main() {
    cin >> n >> sum;
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 0; i < n; i++) f(i, arr[i]);
    cout << ans;

}