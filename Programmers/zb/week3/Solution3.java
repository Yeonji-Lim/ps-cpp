package Programmers.zb.week3;

class Solution {
    private int[] fibo = new int[11];

    public int solution(int N) {
        this.fibo[1] = 1;
        this.fibo[2] = 2;
        for(int i = 3; i < N+1; i++) {
            this.fibo[i] = this.fibo[i-1] + this.fibo[i-2];
        }
        return this.fibo[N];
    }
}

/*
    이거 피보나치임
    그런데 그냥 완전 탐색으로 하면?
    n = 10이라서 괜찮을 거 같긴함
*/
