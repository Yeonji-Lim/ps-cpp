#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

vector<string> split(string str, char delimiter)
{
    vector<string> answer;
    stringstream ss(str);
    string temp;

    while (getline(ss, temp, delimiter))
    {
        answer.push_back(temp);
    }

    return answer;
}

int main() {
    string str;
    getline(cin, str);
    vector<string> result = split(str, ' ');
    return 0;
}