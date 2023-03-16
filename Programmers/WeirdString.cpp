// 12930
#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(string s) {
    string answer = "";
    stringstream ss(s);
    vector<string> words;
    string word;
    while(getline(ss, word, ' ')) {
        for(int i = 0; i < word.size(); i++) {
            if(i%2) {
                if(word[i] < 'a') word[i] = word[i] - 'A' + 'a';
            } else {
                if(word[i] >= 'a') word[i] = word[i] - 'a' + 'A';
            }
        }
        answer += word + ' ';
    }
    answer = answer.substr(0, answer.size()-1);
    return answer;
}