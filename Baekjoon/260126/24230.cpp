#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int>> adj;
vector<int> color;
int cnt = 0;

void dfs(int cur_idx, int par_idx) {
	if (color[cur_idx] != color[par_idx]) {
		cnt++;
	}

	for (int next : adj[cur_idx]) {
		if (next == par_idx)
			continue;
		else
			dfs(next, cur_idx);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	adj.resize(n + 1);
	color.resize(n + 1);

	for (int i = 1; i <= n; i++)
		cin >> color[i];

	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(1, 0);
	cout << cnt;
}
