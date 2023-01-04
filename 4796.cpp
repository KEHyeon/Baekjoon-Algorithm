#include <iostream>
using namespace std;
int a, b, c, num = 1;
int main() {
    while(1) {
        cin >> a >> b >> c;
        if(a == 0) break;
        cout << "Case " << num++ << ": ";
        cout <<  (c / b) * a + min(c % b, a) << "\n";
    }
}