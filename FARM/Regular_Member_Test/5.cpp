/* #5 주민번호로 나이 구하기 */
#include <iostream>
using namespace std;

int find_age(string str){
    int ret, bir;
    if (str[0] >= '0' && str[0] <= '2' && (str[7] == '3' || str[7] == '4'))
        bir = 2000 + (str[0]-'0')*10 + (str[1]-'0');
    else bir = 1900 + (str[0]-'0')*10 + (str[1]-'0');
    ret = 2021 - bir;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int ans;
    string tmp_str;
    cin >> tmp_str;
    ans = find_age(tmp_str);
    if (ans > -1) cout << ans << endl;
    else cout << "잘못된 주민번호" << endl;
    return 0;
}