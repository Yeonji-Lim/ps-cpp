#include <iostream>
#include <vector>
using namespace std;

void customSwap (string &a, string &b) {
    string temp = a;
    a = b;
    b = temp;
}

void wordsSort(vector<string> &words) {
    int shortWordIdx;
    for(int i = 0; i < words.size(); i++) {
        shortWordIdx = i;
        for(int j = i + 1; j < words.size(); j++) {
            if(words[i] == words[j]) {
                words.erase(words.begin() + j);
                continue;
            }
            if(words[shortWordIdx].length() > words[j].length())
                shortWordIdx = j;
            else if (words[shortWordIdx].length() == words[j].length())
                if(words[shortWordIdx]>words[j])
                    shortWordIdx = j;
                else if(words[shortWordIdx] == words[j]) {
                    words.erase(words.begin() + j);
                    continue;
                }
        }
        if(shortWordIdx != i)
            customSwap(words[i], words[shortWordIdx]);
    }
}

int main() {
    int N;
    cin >> N;
    if(N<1 || N>20000) return 0;
    vector<string> words;
    string word;

    for(int i = 0; i < N; i++) {
        cin >> word;
        if(word.length() > 50) return 0;
        words.push_back(word);
    }

    wordsSort(words);

    for(int i = 0; i < words.size(); i++) {
        cout << words[i] << endl;
    }
    return 0;
}
