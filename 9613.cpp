#include <iostream>
using namespace std;
int tc, n;
int arr[100];
int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    cin >> tc;
    while(tc--) {
        cin >> n;
        long long int sum = 0;
        for(int i = 0; i < n; i++) cin >> arr[i];

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                sum += gcd(arr[i], arr[j]);
            }
        }
        cout << sum << "\n";
    }
}