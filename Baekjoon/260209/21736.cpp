#include <iostream>
#include <vector>

using namespace std;

int n, m;
int person_count = 0;
bool visited[601][601];
vector<vector<char>> v(601);

void dfs(int row, int col) {
	visited[row][col] = true;

	if (v[row][col] == 'P')
		person_count++;

	if (row + 1 >= 0 && row + 1 < n && v[row + 1][col] != 'X' && visited[row + 1][col] == false)
		dfs(row + 1, col);
	
	if (col + 1 >= 0 && col + 1 < m && v[row][col + 1] != 'X' && visited[row][col + 1] == false)
		dfs(row, col + 1);
	
	if (row - 1 >= 0 && row - 1 < n && v[row - 1][col] != 'X' && visited[row - 1][col] == false)
		dfs(row - 1, col);

	if (col - 1 >= 0 && col - 1 < m && v[row][col - 1] != 'X' && visited[row][col - 1] == false)
		dfs(row, col - 1);
}

int main() {
	cin >> n >> m;

	char input;

	int I = 0, J = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> input;
			v[i].push_back(input);
			if (input == 'I') {
				I = i, J = j;
			}
		}
	}

	dfs(I, J);

	if (person_count == 0)
		cout << "TT";
	else if (person_count != 0)
		cout << person_count;

	return 0;
}
