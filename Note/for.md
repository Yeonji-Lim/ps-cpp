# vector

vector 탐색시, 사이즈 가지고 음수가 나올 수 있는 식을 조건에 넣을거면 (int)를 붙여주어야 한다.

~~~
    for(int i = v.size()-1; i > (int)v.size()-k-1; i--) {
        ret += (long long)v[i]-1+d;
        v[i] = 1-d;
    }
~~~