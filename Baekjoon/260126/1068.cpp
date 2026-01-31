#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> v[51];
int root;
int del_node;
int leaf_cnt = 0;

void dfs(int current) {
	if (current == del_node)
		return;

	int cnt = 0;
	for (int next : v[current]) {
		if (next == del_node)
			continue;
		dfs(next);
		cnt++;
	}

	if (cnt == 0)
		leaf_cnt++;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	int input;
	for (int i = 0; i < n; i++) {
		cin >> input;

		if (input == -1)
			root = i;
		else
			v[input].push_back(i);
	}

	cin >> del_node;
	if (del_node == root)
		cout << "0";
	else {
		dfs(root);
		cout << leaf_cnt;
	}
}
