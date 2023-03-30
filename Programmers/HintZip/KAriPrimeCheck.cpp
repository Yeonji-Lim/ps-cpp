// 92335
#include <string>
#include <vector>
#include <cmath>

using namespace std;

bool is_prime(long long n) {
    if(n == 1) return false;
    for(long long i = 2; i <= sqrt(n); i++) {
        if(n%i == 0) {
            return false;
        }
    }
    return true;
}

string change_arithmetic(int n, int k) {
    string answer = "";
    while(n) {
        answer = to_string(n%k) + answer;
        n /= k;
    }
    return answer;
}

int solution(int n, int k) {
    int answer = 0;
    string k_ari = change_arithmetic(n, k);
    long long num;
    int si = -1;
    for(int i = 0; i <= k_ari.size(); i++) {
        if(k_ari[i] == '0' || i == k_ari.size()) {
            if(si != -1) {
                num = stoll(k_ari.substr(si, i-si));
                if(is_prime(num)) answer++;
                si = -1;
            }
        } else if(si == -1) si = i;
    }
    return answer;
}