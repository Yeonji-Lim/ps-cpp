# Combination, Permutation 관련 실수 모음

## 조합을 구현하는데, perm의 인덱스가 아니라 perm 그자체의 값으로 조합을 만드려고 함

BOJ/14502
~~~
for(int i = 0; i < perm.size(); i++) {
    if(perm[i]){
        targets[j][0] = candidates[perm[i]].first;
        targets[j][1] = candidates[perm[i]].second;
        j++;
    }
}
~~~