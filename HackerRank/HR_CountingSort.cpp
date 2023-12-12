vector<int> countingSort(vector<int> arr) {
    vector<int> ret(100, 0);
    for(int num: arr) ret[num]++;
    return ret;
}