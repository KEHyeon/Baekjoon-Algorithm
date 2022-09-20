#include <iostream>
using namespace std;
int n;
char arr[51][51];
int max(int a, int b) {
  return a > b ? a : b;
}
void swap(char *a, char *b) {
  char temp = *a;
  *a = *b;
  *b = temp;
}
int ch() {
  int result = 0;
  int cnt = 1;
  for(int i = 0; i < n; i++) {
    char p = arr[i][0];
    for(int j = 1; j< n; j++) {
      if(p != arr[i][j]) {
        result = max(result, cnt);
        cnt = 1;
        p = arr[i][j];
      }
      else cnt++;
    }
    result = max(result, cnt);
    cnt = 1;
  }
  for(int i = 0; i < n; i++) {
    char p = arr[0][i];
    for(int j = 1; j < n; j++) {
      if(p != arr[j][i]) {
        result = max(result, cnt);
        cnt = 1;
        p = arr[j][i];
      }
      else cnt++;
    }
    result = max(result, cnt);
    cnt = 1;
  }
  return result;
}
int main() {
  cin >> n;
  int result = 0;
  for(int i = 0; i < n; i++) cin >> arr[i];
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n - 1; j++) {
      if(arr[i][j] != arr[i][j + 1]) {
        swap(&arr[i][j], &arr[i][j + 1]);
        result = max(ch(), result);
        swap(&arr[i][j], &arr[i][j + 1]);
      }
      if(i + 1 == n) continue;
      if(arr[i][j] != arr[i + 1][j]) {
        swap(&arr[i][j], &arr[i + 1][j]);
        result = max(ch(), result);
        swap(&arr[i][j], &arr[i + 1][j]);
      }
    }
  }
  if(result == 0) cout << n;
  else cout << result;
} 
