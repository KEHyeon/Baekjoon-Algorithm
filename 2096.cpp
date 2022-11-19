#include <bits/stdc++.h>
using namespace std;
int n;
int arr[100000][3], pre[3], cur[3];
int dy[3] = {0, -1, 1};
int solve(bool isMax) {
    pre[0] = arr[0][0];
    pre[1] = arr[0][1];
    pre[2] = arr[0][2];
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < 3; j++) {
            cur[j] = isMax ? 0 : 1000000000;
            for(int k = 0; k < 3; k++) {
                int ny = j + dy[k];
                if(ny < 0 || ny > 2) continue;
                cur[j] = isMax ? max(cur[j], pre[ny] + arr[i][j]) : min(cur[j], pre[ny] + arr[i][j]);
            }
        }
        pre[0] = cur[0];
        pre[1] = cur[1];
        pre[2] = cur[2];
    }
    return isMax ? *(max_element(pre, pre + 3)) : *(min_element(pre, pre + 3));
}
int main() {
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];

    cout << solve(1) << " " << solve(0);

}