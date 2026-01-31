#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
vector<vector<int>> lev(11);

void print_lev(int start, int end, int level) {
	if (start == v.size() - 1 && end == v.size() - 1)
		lev[level].push_back(v[v.size() - 1]);

	if (start >= end)
		return;

	int mid = (start + end) / 2;
	lev[level].push_back(v[mid]);
	print_lev(start, mid, level + 1);
	print_lev(mid + 1, end, level + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int input;
	while (cin >> input) {
		v.push_back(input);
	}

	print_lev(0, v.size() - 1, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < lev[i].size(); j++)
			cout << lev[i][j] << " ";
		cout << '\n';
	}
}
