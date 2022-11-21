#include <bits/stdc++.h>
using namespace std;
int main() {
    for(int i = 1; i <= 500; i++) {
        for(int j = 1; j <= 500; j++) {
            int a, b, c;
            a = i;
            b = j;
            for(int k = 3; k <= 7; k++) {
                int temp;
                if(b % 3 == 0) {
                    temp = b / 3;
                }
                else {
                    temp = a + b;
                }
                a = b;
                b = temp;
            }
            if(b == 40) {
                cout << a << " " << b << "\n";
            }

        }
    }
}