#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int n, m;
int arr[1001][1001];
queue<pair<int, int>> q;
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
int roop_cnt = 0;

void bfs() {
	while (!q.empty()) {
		int X = q.front().first;
		int Y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = X + dx[i];
			int ny = Y + dy[i];

			if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
				if (arr[nx][ny] == 0) {
					arr[nx][ny] = arr[X][Y] + 1;
					q.push({ nx,ny });
				}
			}
		}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];

			if (arr[i][j] == 1)
				q.push({ i,j });
		}
	}

	bfs();

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 0) {
				cout << "-1";
				return 0;
			}

			if (roop_cnt < arr[i][j]) {
				roop_cnt = arr[i][j];
			}
		}
	}

	cout << roop_cnt - 1;
}
