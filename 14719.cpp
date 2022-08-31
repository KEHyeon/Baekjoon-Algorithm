#include <bits/stdc++.h>
using namespace std;
int h, w, ans, first;
int arr[500];
int main() {
	cin >> h >> w;
	for(int i = 0; i < w; i++) {
		cin >> arr[i];
	}
	
	for(int i = 0; i < w; i++) {
		if(arr[i] == 0 && first == 0) continue;
		first = arr[i];
		int firsti = i;
		int wall = 0;
		i++;
		if(firsti == 0 && first  <= arr[i]) {
			firsti = 1;
			first = arr[i];
			i++;
		} 
		if(i >= w - 1) {
			cout << ans;
			return 0;
		}
		int mx = arr[i];
		int mxi = i;
		while(first > arr[i]) {
			wall += arr[i];
			i++;
			if(arr[i] > mx) {
				mx =arr[i];
				mxi = i;
			}
			if(first > arr[i] && i == w - 1) {
				first = min(first, mx);
				for(int j = i; j >= mxi; j--) wall -= arr[i]; 
				ans += (mxi - firsti - 1) * first - wall;
				cout << ans;
				return 0;
			}
		}
		ans += (i - firsti - 1) * first - wall;
		i--;
	}
	cout << ans;
}
