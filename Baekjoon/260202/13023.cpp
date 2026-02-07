#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> v[2001];
bool visited[2001];

bool check(int now, int cnt) {
	if (cnt == 4)
		return true;

	visited[now] = true;

	for (int i = 0; i < v[now].size(); i++) {
		int next = v[now][i];
		if (!visited[next]) {
			if (check(next, cnt + 1))
				return true;
		}
	}

	visited[now] = false;
	return false;
}

void back() {
	for (int i = 0; i < m; i++) {
		if (check(i, 0)) {
			cout << "1";
			return;
		}
	}
	cout << "0";
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		v[a].push_back(b);
		v[b].push_back(a);
	}

	back();
}
