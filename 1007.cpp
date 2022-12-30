#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> dot(20);
bool isSelected[20];
int n;
double ans;
double getMinimum() {
    double sumx = 0;
    double sumy = 0;
    for(int i = 0; i < n; i++) {
        if(isSelected[i]) {
            sumx += dot[i].first;
            sumy += dot[i].second;
        } else {
            sumx -= dot[i].first;
            sumy -= dot[i].second;
        }
    }
    return sqrt(sumx*sumx + sumy*sumy);
}
void selectDot(int depth, int start) {
    if(depth == n / 2) {
        ans = min(getMinimum(), ans);
        return;
    }
    for(int i = start; i < n; i++) {
        if(isSelected[i]) continue;
        isSelected[i] = 1;
        selectDot(depth + 1, i + 1);
        isSelected[i] = 0;
    }
}
int main() {
    int tc; cin >> tc;
    while(tc--) {
        ans = 123456789.0;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            dot[i] = {a, b};
        }
        selectDot(0, 0);
        printf("%0.8f\n", ans);
    }
}