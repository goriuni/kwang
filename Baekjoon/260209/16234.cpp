#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int arr[51][51];
bool visited[51][51];
queue<pair<int, int>> q;
int n, l, r;
int roop_cnt = 0;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int bfs(int x, int y) {
	int sum = arr[x][y];
	vector<pair<int, int>> v;
	v.push_back({ x,y });
	q.push({ x,y });
	visited[x][y] = true;

	int tot_cnt = 0;

	while (!q.empty()) {
		int X = q.front().first;
		int Y = q.front().second;
		q.pop();
		int bef_val = arr[X][Y];

		for (int i = 0; i < 4; i++) {
			int nx = X + dx[i];
			int ny = Y + dy[i];

			if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
				if (abs(bef_val - arr[nx][ny]) >= l &&
					abs(bef_val - arr[nx][ny]) <= r && !visited[nx][ny]) {
					visited[nx][ny] =	true;
					q.push({ nx,ny });
					sum += arr[nx][ny];
					v.push_back(make_pair(nx, ny));
				}
			}
		}
	}
	int avg = sum / v.size();

	for (int i = 0; i < v.size(); i++) {
		int a = v[i].first;
		int b = v[i].second;

		arr[a][b] = avg;
	}
	return v.size();
}

int main() {
	cin >> n >> l >> r;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	
	while (1) {
		bool moved = false;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!visited[i][j]) {
					if (bfs(i, j) >= 2)
						moved = true;
				}
			}
		}
		if (!moved)
			break;
		else {
			roop_cnt += 1;
			memset(visited, false, sizeof(visited));
		}
	}
	cout << roop_cnt;
}
