#include <bits/stdc++.h>

using namespace std;
int sum[200000][27];

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s; cin >> s;
    int n; cin >> n;
    int len = s.size();
    sum[0][s[0] - 'a'] = 1;
    for(int i = 1; i < len; i++) {
        int now = s[i] - 'a';
        for(int j = 0; j < 26; j++) {
            sum[i][j] = sum[i - 1][j] + (j == now);
        }
    }
    while(n--) {
        char c;
        int a, b;
        cin >> c >> a >> b;
        if(a == 0) cout << sum[b][c - 'a'] << '\n';
        else cout << sum[b][c - 'a'] - sum[a - 1][c - 'a'] << "\n";
    }
}#include <bits/stdc++.h>

using namespace std;
int sum[200000][27];

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s; cin >> s;
    int n; cin >> n;
    int len = s.size();
    sum[0][s[0] - 'a'] = 1;
    for(int i = 1; i < len; i++) {
        int now = s[i] - 'a';
        for(int j = 0; j < 26; j++) {
            sum[i][j] = sum[i - 1][j] + (j == now);
        }
    }
    while(n--) {
        char c;
        int a, b;
        cin >> c >> a >> b;
        if(a == 0) cout << sum[b][c - 'a'] << '\n';
        else cout << sum[b][c - 'a'] - sum[a - 1][c - 'a'] << "\n";
    }
}