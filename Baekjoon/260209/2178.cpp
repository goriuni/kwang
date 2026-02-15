#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

int n, m;
vector<string> v;
int visited[101][101];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
queue<pair<int, int>> q;

void bfs(int x, int y) {
	q.push({ x,y });
	visited[x][y] = 1;

	while (!q.empty()) {
		int X = q.front().first;
		int Y = q.front().second;
		q.pop();

		if (X == n - 1 && Y == m - 1) {
			return;
		}

		for (int i = 0; i < 4; i++) {
			int nx = X + dx[i];
			int ny = Y + dy[i];

			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (v[nx][ny] == '1' && visited[nx][ny] == 0) {
					visited[nx][ny] = visited[X][Y] + 1;
					q.push({ nx,ny });
				}
			}
		}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		v.push_back(s);
	}

	bfs(0, 0);
	cout << visited[n - 1][m - 1];
}
