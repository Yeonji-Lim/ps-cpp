# Selection Sort

1. 정렬되지 않은 배열에서 가장 작은 원소를 찾아서 가장 앞의 원소와 위치를 바꾼다.

2. 가장 앞의 원소를 제외하고 뒤의 원소들로 다시 1.을 진행

~~~
void SelectionSort(int A[], int n) {
    /* 입력 : A[0:n－1] , n : 정렬할 원소의 개수. 
       출력 : A[0:n－1] : 정렬된 배열. */
	int i, j, MinIndex;
	for (i ＝ 0; i ＜ n－1; i＋＋){
        MinIndex ＝ i;
        for (j＝MinIndex＋1; j＜n; j＋＋)
            if (A[MinIndex] ＞ A[j])
                MinIndex ＝ j;
        if (MinIndex !＝ i) 
            Swap(&A[i], &A[MinIndex]);
    }	
}
~~~

원소수가 작을 때 사용

i단계에서 n-i만큼 연산 수행

-> 그런데 여기서 자료의 순서와 관계없이 무조건 n-i씩 비교연산 수행

-> 총 n(n+1)/2 번의 연산

## 시간복잡도

최악 : O(n^2)

평균 : O(n^2)

## 제자리성 : O

입력 원소 이외에 i, j, minIndex가 쓰임

-> 상수 크기의 메모리

## 안정성 : X

같은 크기의 원소의 순서가 바뀌지 않을 것이라는 보장이 없다.