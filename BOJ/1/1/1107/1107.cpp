// Failed 코드 - 그리디 방식은 해법이 아니다! 참고 링크 : https://blog.naver.com/occidere/221354997206

// #include <iostream>

// using namespace std;

// int getdist(int i, int j) {
//     return i > j? i-j: j-i;
// }

// int main() {
// 	string n;
// 	int m, tmp, dist, mindist, minpartdist, mini, cur=0;
// 	bool num[10];
// 	fill_n(num, 10, true);
// 	cin >> n >> m;
// 	for(int i = 0; i < m; i++) {
// 		cin >> tmp;
// 		num[tmp] = false;
// 	}

//     mindist = getdist(100, stoi(n));
//     if((int)n.length() > mindist){
//         cout << mindist << '\n';
// 	    return 0;
//     }
// 	tmp = 0;
// 	for(int j = 0; j < n.length(); j++){
// 		tmp = tmp*10 + n[j]-'0';
// 		cur *= 10;
// 		minpartdist = 10;
//         for(int i = 0; i < 10; i++) {
//             if(!num[i]) continue;
//             dist = getdist(tmp, i);
//             //dist = min(getdist(tmp, i), getdist(tmp%10, i));
//             if(dist < minpartdist){
//                 minpartdist = dist;
//                 mini = i;
//             }
//         }
// 		cur += mini;
// 		if(tmp >= mini) tmp -= mini;
// 	}
//     mindist = min(mindist, (int) n.length() + getdist(stoi(n), cur));
// 	cout << mindist << '\n';
// 	return 0;
// }

#include <iostream>

using namespace std;

bool num[10];
string n;
int m, tmp, ans, l;

int getdist(int i, int j) {
    return i > j? i-j: j-i;
}

void dosth(string cur) {
    if((int) cur.length() == 6) return;
    for(int i = 0; i < 10; i++) {
        if(num[i]) {
            cur += to_string(i);
            ans = min(ans, (int) cur.length() + getdist(stoi(n), stoi(cur)));
            dosth(cur);
            cur.pop_back();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fill_n(num, 10, true);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> tmp;
        num[tmp] = false;
    }
    ans = getdist(100, stoi(n));
    tmp = 0;
    l = (int) n.length();
    for(int i = 0; i < l; i++) {
        if(!num[n[i]-'0']){
            tmp = 1;
            break;
        }
    }
    if(tmp == 0) ans = min(ans, l);
    dosth("");
    cout << ans << '\n';
    return 0;
}