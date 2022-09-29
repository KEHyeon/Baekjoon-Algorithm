#include <bits/stdc++.h>
using namespace std;
int n, r, c;
unsigned long long int cnt;
bool flag = 0;
void f(int x, int y, int num) {
	if(flag) return;
    if(num == 1) {
        cnt++;
        if(x == r + 1 && y == c + 1) {
            cout << cnt - 1;
            flag = 1;
        }
        return;
    }
	if(!(x <= r + 1 && r + 1<= x + num - 1 && y <= c + 1&& c + 1<= y + num - 1)) {
		cnt += num * num;
		return;
	}
    else {
        f(x, y, num / 2);
        f(x, y + num / 2, num / 2);
        f(x + num / 2, y, num / 2);
        f(x + num / 2, y + num / 2, num / 2);
    }
}
int main() {
    cin >> n >> r >> c;
    f(1, 1, 1 << n);
}
