#include <iostream>
using namespace std;

int main(){
	int q[10000];
	int n, x, si=0, ei=1;
    cin >> n;
    cin >> x;
    while(x!=-1){
    	if(x == 0){
    	    q[si] = 0;
    	    si++;
    	} else {
    		if(ei-si != n) {
    			q[ei] = x;
    			ei++;
    		}
    	}
    	cin >> x;
    }
    if (si == ei) cout << "empty\n";
    for(int i = si; i < ei; i++) {
        cout << q[i] << "\n";
    }  		
}