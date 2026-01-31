#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, r, q;
vector<vector<int>> v;
int subtree[100001];

void dfs(int cur_idx, int par_idx) {
	subtree[cur_idx] = 1;

	for (int next : v[cur_idx]) {
		if (next != par_idx) {
			dfs(next, cur_idx);
			subtree[cur_idx] += subtree[next];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> r >> q;
	v.resize(n + 1);

	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	dfs(r, -1);

	for (int i = 0; i < q; i++) {
		int input;
		cin >> input;
		cout << subtree[input] << '\n';
	}
}
