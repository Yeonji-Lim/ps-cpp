#include <iostream>
#include <vector>
using namespace std;

void MakeSquare (vector<vector<char>> &result, int num) {

    if(num == 1) {
        result[0].push_back('*');
        return;
    }
    for (int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(i == 1 && j == 1) {
                result[0].push_back(' ');
            }
        }
    }


    return;
}

void PrintSquare (bool isBlank, int num) {
    if(num == 1 && !isBlank) {
        cout << "*";
        return;
    }
    else if(isBlank) {
        for(int i = 1; i <= num; i++)
            cout << "-";
        return;
    }
    for (int i = 1; i <= 9 ; i++) {
        if(i == 5) {
            PrintSquare(true, num/3);
            cout << endl;
            continue;
        }
        PrintSquare(false, num/3);
        if(!(i%3)) cout << endl;
    }
    return;
}

void draw (int i, int j, int N, bool star, vector<char> &map) {
    if(N == 1 && star) {
        map.push_back('*');
        return;
    } else if (N == 1 && !star){
        map.push_back(' ');
    }

    int smallN = N/3;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(i == 1 && j == 1 && star) {
                draw(i,j,smallN,!star,map);
            } else if(i == 1 && j == 1) {

            } else {
                draw(i,j,smallN,star,map);
            }
        }
    }

}

int main() {
    int num;
    cin >> num;
    vector<vector<char>> square(num, vector<char>(num,' '));


    return 0;
}
