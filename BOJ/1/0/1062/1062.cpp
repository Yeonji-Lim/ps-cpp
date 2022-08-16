#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, k;
vector<string> words;
vector<char> candidates;
bool alphabet[26];
int alphabetCnt = 0, answer = 0;

int numOfKnowWords()
{
    int ret = 0;
    bool know = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = 4; j < (int)words[i].length() - 4; j++)
        {
            if (!alphabet[words[i][j] - 'a'])
            {
                know = false;
                break;
            }
        }
        if (know)
            ret++;
        know = true;
    }
    return ret;
}

void findMaxNumOfKnowWords(int cani)
{
    alphabet[candidates[cani] - 'a'] = true;
    alphabetCnt++;
    if (alphabetCnt == k)
    {
        answer = max(answer, numOfKnowWords());
    }
    else
        for (int i = cani + 1; i < (int)candidates.size(); i++)
        {
            findMaxNumOfKnowWords(i);
        }
    alphabet[candidates[cani] - 'a'] = false;
    alphabetCnt--;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    string word;
    for (int i = 0; i < n; i++)
    {
        cin >> word;
        words.push_back(word);
        for (int j = 4; j < (int)word.length() - 4; j++)
        {
            candidates.push_back(word[j]);
        }
    }

    sort(candidates.begin(), candidates.end());
    char prev;
    for (int i = 0; i < (int)candidates.size(); i++)
    {
        if ((candidates[i] == 'a' || candidates[i] == 'c' || candidates[i] == 'i' || candidates[i] == 'n' || candidates[i] == 't') || (i != 0 && candidates[i] == prev))
        {
            candidates.erase(candidates.begin() + i);
            i--;
        }
        else
        {
            prev = candidates[i];
        }
    }

    if (k < 5)
    {
        cout << "0\n";
        return 0;
    }
    k -= 5;
    alphabet['a' - 'a'] = true;
    alphabet['c' - 'a'] = true;
    alphabet['i' - 'a'] = true;
    alphabet['n' - 'a'] = true;
    alphabet['t' - 'a'] = true;

    for (int i = 0; i < (int)candidates.size(); i++)
    {
        findMaxNumOfKnowWords(i);
    }

    cout << answer << '\n';
    return 0;
}