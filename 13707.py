import sys

input = sys.stdin.readline
n, m = map(int, input().split())
dp = [[0] * (m + 1) for _ in range(n + 1)]

for i in range(0, n + 1) :
    dp[i][1] = 1

for i in range(1, m + 1) :
    dp[0][i] = 1
    
def solve2(n, k) :
    for i in range(1, n + 1) :
        for j in range(2, k + 1) :
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000000
    return dp[n][k]


print(solve2(n, m))