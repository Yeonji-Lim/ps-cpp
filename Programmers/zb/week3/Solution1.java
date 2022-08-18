import java.util.*;
import java.io.*;

class Solution {

    boolean[] pn = new boolean[100];

    public int solution(int n) {
        int answer = 0;
        Arrays.fill(pn, true);
        pn[0] = false;
        pn[1] = false;
        for(int i = 2; i < n; i++) {
            if(pn[i]) {
                answer++;
                for(int j = i*2; j < n; j += i) {
                    pn[j] = false;
                }
            }
        }
        return answer;
    }
}