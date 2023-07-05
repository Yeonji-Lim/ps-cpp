// #include <iostream>
// #include <vector>
// #include <queue>

// using namespace std;

// void cprint(vector<int> v) {
//     for(int i =0; i < v.size(); i++) {
//         cout << v[i] << ' ';
//     }
//     cout << '\n';
// }

// queue<vector<int>> q;
// int n, direc;
// int board[16][16];
// int dp[16][16][3]; // 그 위치에서 각 파이프의 방향 별로 최종으로 가는데 몇개의 방법이 있느냐
// int d[3][3][4] = {
// 	{{0,1,0,1}, {-1,0,0,0}, {0,1,1,1}}, // 가로
// 	{{-1,0,0,0}, {1,0,1,0}, {0,1,1,1}}, // 세로
// 	{{1,1,0,1}, {1,1,1,0}, {1,1,1,1}}  // 대각선
// };

// int direcOf(vector<int> tar) {
// 	if(tar[0] == tar[2]) return 0; // 가로
// 	if(tar[1] == tar[3]) return 1; // 세로
// 	else return 2;                   // 대각선
// }

// bool isPossible(vector<int> v) {
// 	for(int i = 0; i < 4; i++)
// 		if(v[i] < 0 || v[i] > n-1) return false;
// 	if(board[v[0]][v[1]] || board[v[2]][v[3]]) return false;
// 	if(direcOf(v) == 2 && ( board[v[0]][v[1]+1] || board[v[2]][v[3]-1] )) return false;
// 	return true;
// }

// // dp[v[0]][v[1]][direc(v)]의 값을 반환 == dp[v[2]][v[3]] 중에 갈 수 있는 것만 택해서 모두 더하기
// int go(vector<int> v) { 
// 	direc = direcOf(v);
// 	if(dp[v[0]][v[1]][direc] != 0){
// 		cout <<"v : "<< v[0] << ' ' << v[1] << ", " << v[2] << ' ' << v[3] << "\ndp: " << dp[v[0]][v[1]][direc] << '\n';
// 		return dp[v[0]][v[1]][direc];
// 	} 
// 	if(v[2] == n-1 && v[3] == n-1) {
// 		dp[v[0]][v[1]][direc] = 1;
// 		cout <<"v : "<< v[0] << ' ' << v[1] << ", " << v[2] << ' ' << v[3] << "\ndp: " << dp[v[0]][v[1]][direc] << '\n';
// 		return dp[v[0]][v[1]][direc];
// 	}
// 	vector<int> nv;
// 	for(int k = 0; k < 3; k++) { // 움직일 방법 선택
// 		if(d[direc][k][0] == -1) continue;
// 		nv = v;
// 		for(int i = 0; i < 4; i++) nv[i] += d[direc][k][i];
// 		if(isPossible(nv)) {
// 			cout << '.';
// 			dp[v[2]][v[3]][k] = go(nv);
// 		}
// 		dp[v[0]][v[1]][direc] += dp[v[2]][v[3]][k];
// 	}
// 	cout <<"v : "<< v[0] << ' ' << v[1] << ", " << v[2] << ' ' << v[3] << "\ndp: " << dp[v[0]][v[1]][direc] << '\n';
// 	return dp[v[0]][v[1]][direc];
// }

// int main(){
// 	ios_base::sync_with_stdio(0);
// 	cin.tie(0);
// 	cin >> n;
// 	for(int i = 0; i < n; i++){
// 		for(int j = 0; j < n; j++){
// 			cin >> board[i][j];
// 		}
// 	}
// 	cout << go(vector<int>{0, 0, 0, 1}) << "\n";
// 	return 0;
// }


#include <iostream>

using namespace std;

int n;
int board[16][16];
int dp[16][16][3]; // 그 위치를 끝으로 하는 파이프를 가로 세로 대각선 으로 놓을 수 있는 방법

// 가로 dp[i][j][0] == dp[i][j-1][0] + dp[i][j-1][2]
// 세로 dp[i][j][1] == dp[i-1][j][1] + dp[i-1][j][2]
// 대각선 dp[i][j][2] == dp[i-1][j-1][0] + dp[i-1][j-1][1] + dp[i-1][j-1][2]

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> board[i][j];
		}
	}
	// 첫 행 가로는 벽이 없다면 모두 갈 수 있으므로 1로 초기화
	for(int i = 1; i < n && !board[0][i]; i++) dp[0][i][0] = 1; 
	// 첫 열 세로는 모두 갈 수 없으므로 0

	// 첫 행과 첫 열을 제외하고 진행
	for(int i = 1; i < n; i++) {
		for(int j = 1; j < n; j++) {
			// 가로 세로는 그 위치만 벽의 유무를 체크하면 된다.
			if(!board[i][j]) {
				dp[i][j][0] = dp[i][j-1][0] + dp[i][j-1][2];
				dp[i][j][1] = dp[i-1][j][1] + dp[i-1][j][2];
				if(!board[i-1][j] && !board[i][j-1])
					dp[i][j][2] = dp[i-1][j-1][0] + dp[i-1][j-1][1] + dp[i-1][j-1][2];
			}
		}
	}
	cout << dp[n-1][n-1][0] + dp[n-1][n-1][1] + dp[n-1][n-1][2] << '\n';
	return 0;
}