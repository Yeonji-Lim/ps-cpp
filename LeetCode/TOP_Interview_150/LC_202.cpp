class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> set;
        int nn;
        while(n!=1 && !set.count(n)) {
            set.insert(n);
            nn = 0;
            while(n>0) {
                nn += (n%10)*(n%10);
                n /= 10;
            }
            n = nn;
        }
        return n==1;
    }
};