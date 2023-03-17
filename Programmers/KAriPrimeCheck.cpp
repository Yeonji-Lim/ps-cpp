// 92335
#include <string>
#include <vector>
#define MS 10000000001

using namespace std;

vector<bool> prime = vector<bool>(MS);
long long last_end = 2;
void set_prime(long long end) {
    if(last_end > end) return;
    for(long long i = last_end; i <= end; i++) {
        if(!prime[i]) continue;
        for(long long j = i*2; j <= end; j += i) {
            if(prime[j]) prime[j] = false;
        }
    }
    last_end = end;
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
    fill(prime.begin(), prime.end(), true);
    prime[0] = false; prime[1] = false;
    string k_ari = change_arithmetic(n, k);
    long long num;
    int si = -1;
    for(int i = 0; i <= k_ari.size(); i++) {
        if(k_ari[i] == '0' || i == k_ari.size()) {
            if(si != -1) {
                num = stoll(k_ari.substr(si, i-si));
                set_prime(num);
                if(prime[num]) answer++;
                si = -1;
            }
        } else if(si == -1) si = i;
    }
    return answer;
}