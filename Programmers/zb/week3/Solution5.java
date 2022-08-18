package Programmers.zb.week3;

import java.util.*;
import java.os.*;

class Solution {
    private int[] capacity;
    private List<int[]> capacities = new ArrayList<>();

    public void makeCapacities(int i) {
        
    }

    public long C (int N, int K) {
        if(N == K || K == 0) return 1;
        int ret = 1;
        int div = 1;
        if(K > N-K) K = N-K;
        for(int i = N; i > N-K; i--) {
            ret *= i;
        }
        for(int i = 1; i <= K; i++) {
            div *= i;
        }
        return ret/div;
    }

    public long P(int N, int K) {
        int ret = 1;
        for(int i = N; i > N-K; i--) {
            ret *= i;
        }
        return ret;
    }

    public long solution(int N, int M, int K, int[] capacity) {
        long answer = 1;
        for(int i = 0; i < capacity.length; i++) {
            answer *= C(N, capacity[i]);
            N -= capacity[i];
        }
        answer *= P(K, M);
        return answer;
    }
}
/*
    그냥 식을 막 바로 구현?
    -> 구현된 식을 돌리는 것은 시간 복잡도 1(TC1) 구현 가능?

    nCk
    시간복잡도 k*k -> 10^2

    nPk
    시간복잡도 k -> 10

    C는 M-1 번, P는 1번, M은 최대 3

    2*10^2 + 10

    약간의 가지치기 k가 n-k보다 클때 바꿔서 해도 됨

    그런데 교실 포용력이 학생 수와 딱 맞지 않을 수 있다... <- 놓침

    5 3 4 

    5 3 2
    5 2 3
    5 1 4
    5 0 4 -> 안됨
    4 3 3
    4 2 4
    4 1 4 -> 안됨
    3 3 4
    3 2 4 -> 안됨 

    미리 넣을 인원수 목록 만들어서 진행?
    시간 복잡도 10^3(1+ 2*10^2 + 10) -> 약 2*10^5
    -> 목록들 만드는거 백트래킹?
*/