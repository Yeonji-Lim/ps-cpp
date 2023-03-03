// https://school.programmers.co.kr/learn/courses/30/lessons/42839#
#include <string>
#include <vector>
#define MS 10000000

using namespace std;

bool sosu[MS];
bool visited[MS];
int ganswer = 0;

void swap(char &a, char &b)
{
    char temp = a;
    a = b;
    b = temp;
}

void permutation(string data, int depth, int n, int r)
{
    if (depth == r)
    {
        int target = 0;
        for (int i = 0; i < depth; i++)
        {
            target *= 10;
            target += data[i] - '0';
        }
        if (!visited[target] && sosu[target])
        {
            ganswer++;
            visited[target] = true;
        }
        return;
    }

    for (int i = depth; i < n; i++)
    {
        swap(data[depth], data[i]);
        permutation(data, depth + 1, n, r);
        swap(data[depth], data[i]);
    }
}

void set_sosu(int size)
{
    sosu[0] = false;
    sosu[1] = false;
    for (int i = 2; i < size; i++)
    {
        for (int j = i * 2; j < size; j += i)
        {
            sosu[j] = false;
        }
    }
}

int solution(string numbers)
{
    fill_n(sosu, MS, true);
    fill_n(visited, MS, false);
    int size = 1;
    vector<bool> perm(numbers.size());
    for (int i = 0; i < numbers.size(); i++)
        size *= 10;
    set_sosu(size);
    for (int i = 1; i <= numbers.size(); i++)
    {
        permutation(numbers, 0, numbers.size(), i);
    }
    return ganswer;
}