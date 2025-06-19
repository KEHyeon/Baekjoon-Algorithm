T = int(input())
vis = {}
ans = 0
for _ in range(T):
    a, b = map(int, input().split())
    for i in range(a, a + 10) :
        for j in range(b, b + 10) :
            if (i, j) not in vis :
                vis[(i, j)] = True
                ans = ans + 1
print(ans)