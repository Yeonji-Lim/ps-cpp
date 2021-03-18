/* Sovled - 6540KB 160ms */
//#include <iostream>
//#include <vector>
//using namespace std;
//
//void quickSort(vector<pair<int, int>> &locations) {
//
//    if(locations.size() <= 1) return;
//
//    int pivotInx = locations.size()/2;
//    vector<pair<int, int>> left;
//    vector<pair<int, int>> right;
//
//    for(int i = 0; i < locations.size(); i++) {
//        if(i == pivotInx) continue;
//        if(locations[i].second < locations[pivotInx].second) {
//            left.push_back(locations[i]);
//        }
//        else if (locations[i].second > locations[pivotInx].second) {
//            right.push_back(locations[i]);
//        }
//        else {
//            if(locations[i].first <= locations[pivotInx].first) {
//                left.push_back(locations[i]);
//            } else {
//                right.push_back(locations[i]);
//            }
//        }
//    }
//
//    quickSort(left);
//    quickSort(right);
//
//    left.push_back(locations[pivotInx]);
//    left.insert(left.end(), right.begin(), right.end());
//    locations = left;
//    return;
//}
//
//int main() {
//    int N;
//    cin >> N;
//    vector<pair<int, int>> locations;
//    int a, b;
//    for(int i=0; i<N; i++) {
//        cin >> a >> b;
//        locations.push_back(pair<int, int>(a, b));
//    }
//
//    quickSort(locations);
//
//    for(int i=0; i<N; i++) {
//        printf("%d %d\n", locations[i].first, locations[i].second);
//    }
//
//    return 0;
//}
