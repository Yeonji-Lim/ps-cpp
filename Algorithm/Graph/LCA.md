# SDS - LCA

오늘 강의에서 LCA 의 핵심 모듈의 코드를 공유합니다. 문제에 대한 Full 소스코드 는 스스로의 힘으로 만들어보시기 바랍니다.

희소 테이블 (Sparse Table, 점핑할 때 사용)

```cpp
int Parent[18][100001];  // 노드 10만개인 경우

// in main code
for (int r = 1; r < 18; r++) {
  for (int i = 1; i <= 100000; i++) {
    Parent[r][i] = Parent[r - 1][Parent[r - 1][i]]; // Parent[r][i] 는 Parent[r-1][i] 의 2^(r-1) 번째 부모
  }
}
```

Depth 맞추기

```cpp
int diff = Depth[a] - Depth[b];  // a 의 depth 가 더 깊다고 가정.
for (int r = 0; diff > 0; r++) {
  if (diff & 1) {
    a = Parent[r][a];
  }
  diff >>= 1;
}
```

두 노드의 Depth 가 같을 때 LCA 찾기

```cpp
while (a != b) {
  int r;
  for (r = 0; r < 18; r++) {
    if (Parent[r][a] == Parent[r][b]) break;
  }
  if(r > 0) --r;
  a = Parent[r][a], b = Parent[r][b];
}

// a 또는 b 가 LCA 가 됨.
```