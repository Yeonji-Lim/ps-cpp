//#include <iostream>
//#include <vector>
//using namespace std;
//
//int compareString(string row, string testString) {
//    int result=0;
//    for(int i=0; i<8; i++) {
//        if (row[i] != testString[i]) result++;
//    }
//    return result;
//}
//
//int calculateDiff(vector<string> chess, int i, int j, string firstString, string secondString) {
//    int diff = 0;
//    for(int k=0; k<8; k++) {
//        if(k%2) {
//            diff += compareString(chess[i + k].substr(j, j + 7), firstString);
//        } else {
//            diff += compareString(chess[i + k].substr(j, j + 7), secondString);
//        }
//    }
//    return diff;
//}
//
//void findNumOfSquare (vector<string> chess, int N, int M) {
//    int min = N * M;
//    int diff = 0;
//    int diff_2 = 0;
//    char firstColor = 'B';
//    char secondColor = 'W';
//    string temp;
//    string firstString = "BWBWBWBW";
//    string secondString = "WBWBWBWB";
//
//    //i,j는 추출할 사각형의 왼쪽 위 시작점
//    for (int j=0; j<M-7; j++) {
//        for (int i=0; i<N-7; i++) {
//            diff = calculateDiff(chess, i, j, firstString, secondString);
//            if(min > diff) min = diff;
//            diff = calculateDiff(chess, i, j, secondString, firstString);
//            if(min > diff) min = diff;
//        }
//    }
//
//    cout << min;
//}
//
//int calculateDiff (string chess[], string test[], int startI, int startJ) {
//    int result = 0;
//    for(int i=0; i<(int)chess->size(); i++) {
//        for(int j=0; j<(int)chess[0].length(); j++) {
//            if(chess[startI+i][startJ+j] != test[i][j]) result++;
//        }
//    }
//    return result;
//}
//
//int main() {
//    int N, M;
//    cin >> N >> M;
//    if(N<8 || N>50 || M<8 || M>50) return 0;
//    string chess[N][M];
//    string str;
//    int min
//    for(int i=0; i<N; i++) {
//        cin >> str;
//        for(int j=0; j<M; j) {
//            chess.push_back(str);
//        }
//    }
//
//    string case1 = {
//            "BWBWBWBW",
//            "WBWBWBWB",
//            "BWBWBWBW",
//            "WBWBWBWB",
//            "BWBWBWBW",
//            "WBWBWBWB",
//            "BWBWBWBW",
//            "WBWBWBWB"
//    };
//
//    string case2 = {
//            "WBWBWBWB",
//            "BWBWBWBW",
//            "WBWBWBWB",
//            "BWBWBWBW",
//            "WBWBWBWB",
//            "BWBWBWBW",
//            "WBWBWBWB",
//            "BWBWBWBW"
//    };
//
//    for (int j=0; j<M-7; j++) {
//        for (int i = 0; i < N - 7; i++) {
//            if(min > calculateDiff(chess, case1, i, j)) min = calculateDiff(chess, case1, i, j);
//        }
//    }
//
//    return 0;
//}

#include <iostream>
#include <vector>
using namespace std;

int paintNumber (int starti, int startj, string first, string second, vector<string> chess) {
    string test;
    int result = 0;
    for(int i = 0; i < 8; i++) {
        //i번째 행에서 비교할 문자열
        test = chess[starti+i].substr(startj, 8);
        printf("chess의 %d번째 줄의 %d번 문자 부터 시작하는 문자열 : %s\n",starti+i,startj,test.c_str());
        if(!(i%2)) { //first와 비교해야하는 경우
            for(int j = 0; j < 8; j++) {
//                printf("test[j] : %c, first[j] : %c\n", test[j], first[j]);
                if(test[j] != first[j])  result++;
            }
        } else {
            for(int j = 0; j < 8; j++) {
//                printf("test[j] : %c, second[j] : %c\n", test[j], second[j]);
                if(test[j] != second[j])  result++;
            }
        }
    }
//    printf("result : %d\n------------------------------------------------------\n", result);
    return result;
}

void minPaintNumber (vector<string> chess) {
    int result = (int) (chess.size() * chess[0].length());
    string first = "BWBWBWBW";
    string second = "WBWBWBWB";
    for(int i = 0; i < (int)chess.size()-7; i++) {
        for(int j = 0; j < (int)chess[0].length()-7; j++) {
            if(paintNumber(i,j,first,second,chess) < result) result = paintNumber(i,j,first,second,chess);
            if(paintNumber(i,j,second,first,chess) < result) result = paintNumber(i,j,second,first,chess);
        }
    }
    printf("%d\n", result);
    return;
}
int main () {
    //행의 수가 N, 열의 수가 M
    int N, M;
    cin >> N >> M;
    vector<string> chess;
    string row;
    for(int i=0; i<N; i++) {
        cin >> row;
        chess.push_back(row);
    }
    minPaintNumber(chess);
    return 0;
}