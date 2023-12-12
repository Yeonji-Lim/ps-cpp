void plusMinus(vector<int> arr) {
    int n = arr.size(), plus = 0, minus = 0, zero = 0;
    for(int a : arr) {
        if(a > 0) plus++;
        else if(a < 0) minus++;
        else zero++;
    }
    cout << fixed;
    cout.precision(6);
    cout << (double)plus/n << "\n";
    cout << (double)minus/n << "\n";
    cout << (double)zero/n << "\n";
}