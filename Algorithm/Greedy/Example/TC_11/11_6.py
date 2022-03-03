import heapq

n, k = map(int, input.split())
food_times = list(map(int, input.split()))

if sum(food_times) <= k:
    print(-1)

q = []
for i in range(len(food_times)):
    heapq.heappush(q, (food_times[i], i+1))

sum_value = 0 # 먹기 위해 사용한 시간
previous = 0 # 직전에 다 먹은 음식 시간
length = len(food_times) # 남은 음식의 개수

# [sum_value + (현재의 음식시간 - 이전 음식시간) * 현재 음식 개수] 와 k를 비교 
while sum_value + ((q[0][0]-previous) * length) <= k:
    now = heapq.heappop(q)[0]
    sum_value += (now-previous) * length
    length -= 1
    previous = now

# 남은 음식 중에서 몇번째 음식인지 확인하여 출력
result = sorted(q, key=lambda x: x[1])
print(result[(k-sum_value)%length][1])