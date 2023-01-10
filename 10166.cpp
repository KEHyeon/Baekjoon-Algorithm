#include <bits/stdc++.h>
using namespace std;

int cnt, d1, d2;
bool arr[2001][2001];
int main() {
    cin >> d1 >> d2;
    for(int i = d1; i <= d2; i++) {
        for(int j = 1; j <= i; j++) {
            int x = gcd(i,j);
            arr[i/x][j/x] = 1;
        }
    }
    for(int i = 0; i < 2001; i++) {
        for(int j = 0; j < 2001; j++) {
            cnt += arr[i][j];
        }
    }
    cout << cnt;
}