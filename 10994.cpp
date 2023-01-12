#include <bits/stdc++.h>
using namespace std;
int n;
bool star[10000][10000];
void makeStar(int x) {
    int len = 1 + (4 * (n - 1)) - 4 * (x - 1);
    int start = 1 + 2 * (x - 1);
    for(int i = start; i < start + len; i++) {
        for(int j = start; j < start + len; j++) {
            if(i == start || i == start + len - 1) star[i][j] = 1;
            if(j == start || j == start + len - 1) star[i][j] = 1;
        }
    }
}
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        makeStar(i);
    }
    for(int i = 1; i <= 1 + (4 * (n - 1)); i++) {
        for(int j = 1; j <= 1 + (4 * (n - 1)); j++) {
            if(star[i][j]) cout << '*';
            else cout << " ";
        }
        cout << '\n';
    }
}