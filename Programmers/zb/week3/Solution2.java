import java.util.*;
import java.io.*;

class Solution {
    public int solution(String[] names) {
        Set<String> nameSet = new HashSet<>(Arrays.asList(names));
        int n = nameSet.size();
        int k = 4;

        int numer = n;
        int deno = 1;
        for (int i = 1; i < k; i++) {
            numer *= n - i;
            deno *= i + 1;
        }

        return (int) (numer / deno);
    }
}

/*
 * 다 다른거일때 이름 100개
 * 100C4 = 3921225
 * 1초 = 1억 = 10^8
 * ..?
 * set 등을 쓴게 문제? -> 아님.. 여전히 시간초과임
 * 
 * 경우의 수를 구하는데, 그 내용은 중요하지 않다면 그냥 공식을 이용해도 된다.
 */