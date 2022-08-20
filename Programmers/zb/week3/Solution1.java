import java.util.*;
import java.io.*;

class Solution {
    public int solution(int n) {
        int[] pn = new int[n];
        int answer = 0;
        Arrays.fill(pn, 1);
        pn[0] = 0;
        pn[1] = 0;
        for (int i = 2; i <= (int) Math.sqrt(n); i++) {
            if (pn[i] == 1) {
                for (int j = i * 2; j < n; j += i) {
                    pn[j] = 0;
                }
            }
        }
        return Arrays.stream(pn).sum();
    }
}