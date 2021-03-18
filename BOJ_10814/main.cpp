/* Failed */
//#include <iostream>
//#include <vector>
//using namespace std;
//
//void ageSort(vector<tuple<int, int, string>> &people) {
//    int minIdx;
//    for(int i=0; i<people.size(); i++) {
//        minIdx = i;
//        for(int j=i+1; j<people.size(); j++) {
//            if (get<1>(people[i]) > get<1>(people[j]))
//                minIdx = j;
//            else if (get<1>(people[i]) == get<1>(people[j]))
//                if (get<0>(people[i]) > get<0>(people[j]))
//                    minIdx = j;
//        }
//        if(minIdx == i) continue;
//        tuple<int, int, string> temp = people[i];
//        people[i] = people[minIdx];
//        people[minIdx] = temp;
//    }
//}
//
//int main() {
//    int N;
//    cin >> N;
//    if(N<1||N>100000) return 0;
//    vector<tuple<int, int, string>> people;
//    int age;
//    string name;
//
//    for(int i = 0; i < N; i++) {
//        cin >> age >> name;
//        if(age<1||age>200||name.length()>100) return 0;
//        people.push_back(make_tuple(i,age,name));
//    }
//
//    ageSort(people);
//
//    for(int i = 0; i < N; i++) {
//        cout << get<1>(people[i]) << " " << get<2>(people[i]) << endl;
//    }
//    return 0;
//}
