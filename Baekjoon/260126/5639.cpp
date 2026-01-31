#include <iostream>
#include <vector>

using namespace std;

vector<int> preorder;

void postorder(int start, int end) {
	if (start >= end)
		return;

	int root = preorder[start];
	int split_idx = start + 1;
	while (split_idx < end) {
		if (preorder[split_idx] > root)
			break;
		split_idx++;
	}

	postorder(start + 1, split_idx);
	postorder(split_idx, end);
	cout << root << '\n';
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int input;
	while (cin >> input) {
		preorder.push_back(input);
	}
	postorder(0, preorder.size());
}
