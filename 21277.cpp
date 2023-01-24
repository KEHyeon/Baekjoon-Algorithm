#include <bits/stdc++.h>
using namespace std;
int n1, m1, n2, m2, ans = 12345678;
char p1[51][51];
char p2[51][51];

void rotate(int x, int y) {
    char newP[51][51];
    for(int i = 0; i < n2; i++) {
        for(int j = 0; j < m2; j++) {
            newP[j][n2 - i - 1] = p2[i][j];
        }
    }
    swap(n2, m2);
    for(int i = 0; i < n2; i++) {
        for(int j = 0; j < m2; j++) {
            p2[i][j] = newP[i][j];
        }
    }
    for(int i = 0; i < n2; i++) {
        if(x + i >= n1) break;
        for(int j = 0; j < m2; j++) {
            if(y + j >= m1) break;
            if(p2[i][j] == '1' && p1[x + i][y + j] == '1') return;
        }
    }
    ans = min(ans, max((x + n2), n1) * max(y + m2, m1));

}
void rotate2() {
    char newP[51][51];
    for(int i = 0; i < n1; i++) {
        for(int j = 0; j < m1; j++) {
            newP[j][n1 - i - 1] = p1[i][j];
        }
    }
    swap(n1, m1);
    for(int i = 0; i < n1; i++) {
        for(int j = 0; j < m1; j++) {
            p1[i][j] = newP[i][j];
        }
    }
}
int main() {
    cin >> n1 >> m1;
    for(int i = 0; i < n1; i++) {
        cin >> p1[i];
    }
    cin >> n2 >> m2;
    for(int i = 0; i < n2; i++) {
        cin >> p2[i];
    }
    for(int i = 0; i <= n1; i++) {
        for(int j = 0; j <= m1; j++) {
            rotate(i, j);
            rotate(i, j);
            rotate(i, j);
            rotate(i, j);
        }
    }
    rotate2();
    for(int i = 0; i <= n1; i++) {
        for(int j = 0; j <= m1; j++) {
            rotate(i, j);
            rotate(i, j);
            rotate(i, j);
            rotate(i, j);
        }
    }
    rotate2();
    for(int i = 0; i <= n1; i++) {
        for(int j = 0; j <= m1; j++) {
            rotate(i, j);
            rotate(i, j);
            rotate(i, j);
            rotate(i, j);
        }
    }
    rotate2();
    for(int i = 0; i <= n1; i++) {
        for(int j = 0; j <= m1; j++) {
            rotate(i, j);
            rotate(i, j);
            rotate(i, j);
            rotate(i, j);
        }
    }
    cout << ans;
}