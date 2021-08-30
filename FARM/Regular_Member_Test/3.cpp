/* #3 중복 찾기 */
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

vector<string> split(string str, char delimiter) {
    vector<string> answer;
    stringstream ss(str);
    string temp;

    while (getline(ss, temp, delimiter)) { answer.push_back(temp); }

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int answer = 0;
    string tmp_str;
    getline(cin, tmp_str);
    vector<string> strli = split(tmp_str, ' ');
    for(int i = 0; i < strli.size(); i++) {
        for(int j = i+1; j < strli.size(); j++) {
            if(strli[i] == strli[j]) { answer = 1; break; }
        }
    }
    cout << answer << endl;
    return 0;
}