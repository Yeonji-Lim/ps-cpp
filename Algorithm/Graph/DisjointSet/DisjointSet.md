## 서로소 집합 알고리즘

그래프 알고리즘의 일종.
어떤 원소들이 주어졌을 때 전체를 서로소인 부분집합으로 나눈다. 

마치 스택의 push와 pop처럼 union 연산과, find 연산으로 나누어져 있다.
트리 자료자료를 사용하여, 부모자식관계로 집합에 속하는 것을 표현한다.

노드가 주어지면 부모 테이블을 만들고, 각각 자기 자신을 부모로 설정한다.
그리고 두 원소에 대한 union 연산이 주어지는데 
이에 따라 보통 더 작은 숫자를 부모, 큰 숫자를 자식으로 설정한다.

그리고 반복해서 부모 테이블을 탐색하면서 부모테이블을 갱신한다. 

..

뭔가 보고 나중에 다시 봐서 그런지 모르겠지만

잘 이해했다고 생각했는데 막상 코드를 짜려고 보니 잘 안되었다.

union과 find로 나눠지는데,

find는 무조건 부모가 자기 자신이 아니면 따라가기만 하면 된다. -> 왜냐하면 어차피 테이블에 부모는 자신보다 숫자가 작은 것으로 설정되어 있음

union은 두 수가 있을때 그냥 무조건적으로 가장 위 부모를 따라간다(각각 find) 그리고 최종 부모끼리 비교


그런데 이렇게 했을 때 find가 비효율적으로 동작한다.

최악의 경우 모든 노드를 확인하므로 O(V) -> 모두 같은 부모를 갖는 경우


find 혹은 union 연산의 개수가 M개일 때, 시간 복잡도가 O(VM)이 된다.

이 find는 경로압축기법(Path Compression)을 적용하면 개선시킬 수 있다.


find 함수를 재귀저긍로 호출해서 부모 테이블 값을 갱신한다.

단지 그냥 따라가기만 했다면, 저장을 병행한다.

~~~
//기존 find 함수
int find_parent(int child) {
    if(parent[child] != child)
        return find_parent(parent[child]);
    return child;
}

//개선된 find 함수
int find_parent(int child) {
    if(parent[child] != child)
        parent[child] = find_parent(parent[child]);
    return parent[child];
}
~~~

이렇게 바꾸면 훨씬 더 루트 노드에 빠르게 접근할 수 있다.
