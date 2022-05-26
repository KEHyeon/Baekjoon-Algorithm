#include <iostream>
using namespace std;
int n, m;
bool isUsed[9];
int result[8];
void f(int num) {
	if(num == m) {
		for(int i = 0; i < m; i++) {
			cout << result[i] << " ";
		}
		cout << "\n";
		return;
	}
	for(int i = 1; i <= n; i++) {
		if(isUsed[i] == 1) continue;
		isUsed[i] = 1;
		result[num] = i;
		f(num + 1);
		isUsed[i] = 0;
	}
}
int main() {
	cin >> n >> m;
	f(0);
}
