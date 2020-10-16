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

void stringSort(vector<string> &words) {
    if(words.size() <= 1) return;
    vector<string> left;
    vector<string> right;
    int pivotIdx = words.size()/2;
    for(int i = 0; i<words.size(); i++) {

    }
}

int main() {
    int N;
    cin >> N;
    vector<string> words;
    string word;

    for(int i = 0; i < N; i++) {
        cin >> word;
        words.push_back(word);
    }

    wordsSort(words);

    for(int i = 0; i < words.size(); i++) {
        printf("%s\n", words[i].c_str());
    }
    return 0;
}
