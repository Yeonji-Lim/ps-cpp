#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr) {
    int answer = 1;
    bool done = false;
    bool con = false;
    while(!done){
        int t;
        for(int a : arr) {
            if(a==1) {
                done = true;
                break;
            }
        }
        if(done) break;
        for(t = 2; t < 51; t++) {
            for(int a : arr) {
                if(a%t!=0) {
                    con = true;
                    break;
                }
            }
            if(!con) {
                answer *= t;
                for(int i=0; i < arr.size(); i++) {
                    arr[i] /= t;
                }
                break;
            }
        }
    }
    for(int a : arr) {
        answer *= a;
    }
    return answer;
}