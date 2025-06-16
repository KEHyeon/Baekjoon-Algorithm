import sys
import math

input = sys.stdin.readline
n = int(input())
cntMap = dict()

ans = 0
while(n != 0) :
    key = n % 10
    cntMap[key] = cntMap.get(key, 0) + 1
    if key == 9 or key == 6 :
        ans = max(ans, math.cell((cntMap.get(9, 0) + cntMap.get(6, 0)) / 2))
    else :
        ans = max(ans, round(cntMap[key]))
    n //= 10

print(ans)