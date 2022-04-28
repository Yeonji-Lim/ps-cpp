# Solution in Book
from collections import deque

n, m, k, x = map(int, input().split())
graph = [[] for _ in range(n+1)]

for _ in range(m):
    # 이 부분이 다름 : 나는 인접 행렬로 만든 반면, 인접 리스트 방식과 같음
    a, b = map(int, input().split())
    graph[a].append(b)

distance = [-1]*(n+1)
distance[x] = 0

q = deque([x])
while q:
    now = q.popleft()
    for next_node in graph[now]:
        # 이 부분이 다름 : 방문하지 않았을 때 현재 위치가 가진 거리를 무조건 대입
        if distance[next_node] == -1:
            distance[next_node] = distance[now]+1
            q.append(next_node)

check = False
for i in range(1, n+1):
    if distance[i] == k:
        print(i)
        check = True

if check == False:
    print(-1)