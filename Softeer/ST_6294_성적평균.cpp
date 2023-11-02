#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
  vector<int> score;
  int n, k, tmp, si, ei, ans;
  double real_ans;
  cin >> n >> k;
  for(int i = 0; i < n; i++) {
    cin >> tmp;
    score.push_back(tmp);
  }
  cout << fixed;
  cout.precision(2);
  for(int i = 0; i < k; i++) {
    cin >> si >> ei;
    ans = 0; tmp = 0;
    for(int j = si-1; j < ei; j++) {
      ans += score[j];
      tmp++;
    }
    real_ans = (double)(ans*100)/tmp;
    cout << real_ans/100 << '\n';
  }
  return 0;
}