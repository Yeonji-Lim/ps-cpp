void miniMaxSum(vector<int> arr) {
    double ans = 0;
    int minel = INT_MAX, maxel = 0;
    for(int a : arr) {
        ans += a;
        minel = min(minel, a);
        maxel = max(maxel, a);
    }
    cout << fixed;
    cout.precision(0);
    cout << ans-maxel << " " << ans-minel <<"\n";
}