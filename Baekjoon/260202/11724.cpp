#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m, v;
bool visited[1001];
vector<vector<int>> adj(1001);
queue<int> q;

void dfs(int start) {
	visited[start] = true;
	for (int next : adj[start]) {
		if (!visited[next])
			dfs(next);
	}
}

int main() {
	cin >> n >> m;

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	int count = 0;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			count++;
			dfs(i);
		}
	}

	cout << count;
	return 0;
}
