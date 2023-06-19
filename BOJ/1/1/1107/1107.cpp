#include <iostream>

using namespace std;

int getdist(int i, int j) {
    return i > j? i-j: j-i;
}

int main() {
	string n;
	int m, tmp, dist, mindist, minpartdist, mini, cur=0;
	bool num[10];
	fill_n(num, 10, true);
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		cin >> tmp;
		num[tmp] = false;
	}

    mindist = getdist(100, stoi(n));
    if((int)n.length() > mindist){
        cout << mindist << '\n';
	    return 0;
    }
	tmp = 0;
	for(int j = 0; j < n.length(); j++){
		tmp = tmp*10 + n[j]-'0';
		cur *= 10;
		minpartdist = 10;
        for(int i = 0; i < 10; i++) {
            if(!num[i]) continue;
            dist = getdist(tmp, i);
            //dist = min(getdist(tmp, i), getdist(tmp%10, i));
            if(dist < minpartdist){
                minpartdist = dist;
                mini = i;
            }
        }
		cur += mini;
		if(tmp >= mini) tmp -= mini;
	}
    mindist = min(mindist, (int) n.length() + getdist(stoi(n), cur));
	cout << mindist << '\n';
	return 0;
}