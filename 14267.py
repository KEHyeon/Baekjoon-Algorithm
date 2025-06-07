import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

n, m = map(int, input().split())
supervisors = list(map(int, input().split()))
graph = [[] for _ in range(n + 1)]
praise = [0] * (n + 1)

# 트리 구조 구성
for i, boss in enumerate(supervisors):
    if boss == -1:
        continue
    graph[boss].append(i + 1)  # 직원 번호는 1부터 시작하므로

# 칭찬 받은 직원에만 점수 누적
for _ in range(m):
    i, w = map(int, input().split())
    praise[i] += w

# DFS로 칭찬 전파
def dfs(cur):
    for nxt in graph[cur]:
        praise[nxt] += praise[cur]
        dfs(nxt)

dfs(1)

# 결과 출력
print(' '.join(map(str, praise[1:])))
