#include <iostream>
using namespace std;

int main() {
    int n, ans = 0; cin >> n;
    n = 1000 - n;
    int arr[6] = {500, 100, 50, 10, 5, 1};
    for(int i = 0; i < 6; i++) {
        if(n >= arr[i]) {
            ans += n / arr[i];
            n %= arr[i];
        }
        if(n == 0) break;
    }
    cout << ans;
}