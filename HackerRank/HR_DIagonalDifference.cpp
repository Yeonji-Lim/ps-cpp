int diagonalDifference(vector<vector<int>> arr) {
    int n = arr.size(), l = 0, r = 0;
    for(int i = 0; i < n; i++) {
        l += arr[i][i];
        r += arr[i][n-1-i];
    }
    return (l>r)?l-r:r-l;
}