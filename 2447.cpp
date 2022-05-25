#include <bits/stdc++.h>

void star(char *arr, int n, int n2) {
    if(n == 1) *arr = '*';
    else {for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(i == 1 && j == 1) continue;
            star(arr + (n / 3 * i * n2) + (j * n / 3), n / 3, n2);
        }
    }}
}
int main() {
    int n; scanf("%d", &n);
    char a[n * n + 1];
    star(a, n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(*(a + i * n + j) == '*')printf("%c", *(a + i * n + j));
            else printf(" ");
        }
        printf("\n");
    }
}
