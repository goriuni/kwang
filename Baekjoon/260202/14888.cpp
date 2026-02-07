#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> v;
int arr[4];
int MAX = -1e9;
int MIN = 1e9;

void back(int result, int idx) {
	if (idx == n) {
		if (result > MAX)
			MAX = result;
		if (result < MIN)
			MIN = result;
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (arr[i] > 0) {
			arr[i] -= 1;
			if (i == 0) {
				int new_result = result + v[idx];
				back(new_result, idx + 1);
				arr[i] += 1;
			}
			else if (i == 1) {
				int new_result = result - v[idx];
				back(new_result, idx + 1);
				arr[i] += 1;
			}
			else if (i == 2) {
				int new_result = result * v[idx];
				back(new_result, idx + 1);
				arr[i] += 1;
			}
			else if (i == 3) {
				int new_result = result / v[idx];
				back(new_result, idx + 1);
				arr[i] += 1;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		v.push_back(input);
	}

	for (int i = 0; i < 4; i++) {
		cin >> arr[i];
	}

	back(v[0], 1);
	cout << MAX << '\n' << MIN;
}
