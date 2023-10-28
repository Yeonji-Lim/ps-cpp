#include <string>
#include <vector>
#include <set>

using namespace std;

bool solution(vector<string> phone_book) {
    set<string> s;
    for(string phone : phone_book ) {
        for(int i = 1; i < phone.length(); i++) {
            if(s.find(phone.substr(0, i)) != s.end()) return false;
        }
        s.insert(phone);
    }
    return true;
}