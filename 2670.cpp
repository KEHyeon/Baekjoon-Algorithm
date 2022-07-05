#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    double arr[n];
    double mul[n];
    double ans = -1;
    mul[0] = 1;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        if(i == 0) {
            mul[0] = arr[0];
        }
        else {
            mul[i] = mul[i - 1] * arr[i];
        }
    }
    if(n == 1) {
        printf("%.3f", arr[0]);
        return 0;
    }
    for(int i = 0; i < n; i++) {
        if(ans < mul[i]) ans = mul[i];
        for(int j = i - 1; j >= 0; j--) {
            if(mul[j] == 0) break;
            if(mul[i] / mul[j] > ans) ans = mul[i] / mul[j];
        }
    }
    printf("%.3f", ans);
}