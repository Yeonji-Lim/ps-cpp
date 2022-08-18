package Programmers.zb.week3;

import java.util.*;
import java.io.*;

class Solution {
    private List<String> names = new ArrayList<String>();
    private int answer = 0;
    private int numWinner = 4;
    private int cnt = 0;
    
    public void findAnswer(int si) {
        cnt+=1;
        if(cnt == this.numWinner) {
            answer+=1;
        } else for(int i = si+1; i < this.names.size(); i++) {
            findAnswer(i);
        }
        cnt-=1;
    }

    public int solution(String[] names) {
        Arrays.sort(names);
        String prev = "";
        for(int i = 0; i < names.length; i++) {
            if(!prev.equals(names[i])) {
                prev = names[i];
                this.names.add(names[i]);
            }
        }
        for(int i = 0; i < this.names.size(); i++) {
            this.findAnswer(i);
        }
        return this.answer;
    }
}

/*
    다 다른거일때 이름 100개
    100C4
    25*33*49*97 = 25334997 = 2*10^7
    1초 = 1억 = 10^8
    ..?
    set 등을 쓴게 문제? -> 아님.. 여전히 시간초과임
*/