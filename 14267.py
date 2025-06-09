import sys

input = sys.stdin.readline
sys.setrecursionlimit(10**6)
n, m = map(int, input().split())
praise = [0] * (n + 1)
graph = [[] for _ in range(100001)]

praise = [0] * (n + 1)

for i, x in enumerate(map(int, input().split()) ):
    if x == -1:
        continue
    graph[x].append(i + 1)

def dfs(cur):
    for nxt in  graph[cur]:
        praise[nxt] += praise[cur] 
        dfs(nxt)

for _ in range(m):
    i, w = map(int, input().split())
    praise[i] += w

for x in range(n):
    dfs(x + 1)

for i in range(n):
    print(praise[i + 1], end=" ")