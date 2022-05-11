#include <string>
#include <vector>

using namespace std;

string solution(string p)
{
    if (p == "")
        return p;
    string answer = "";
    int i, state = 0;
    bool right = true;
    for (i = 0; i < p.length(); i++)
    {
        if (p[i] == '(')
            state += 1;
        else
            state -= 1;
        if (state < 0)
            right = false;
        if (state == 0)
            break;
    }
    string u = p.substr(0, i + 1);
    string v = p.substr(i + 1);
    if (right)
        return u + solution(v);
    else
    {
        string tmp = "";
        for (i = 1; i < u.length() - 1; i++)
        {
            if (u[i] == '(')
                tmp += ')';
            else
                tmp += '(';
        }
        return "(" + solution(v) + ")" + tmp;
    }
    return answer;
}