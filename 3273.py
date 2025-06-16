import sys
import math

n = int(input())                           
numbers = list(map(int, input().split()))  
x = int(input())                            
vis = [False] * 1000001
for i in numbers :
    vis[i] = True
ans = 0
for i in numbers :
    if(x - i < 0 and x - i > 1000000) :
        continue
    if(vis[x - i]) :
        ans = ans + 1

print(int(ans / 2))