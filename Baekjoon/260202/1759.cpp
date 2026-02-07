#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<char> v;
int l, c;
string str;

void back(int idx, int mo_cnt, int ja_cnt) {
	str.push_back(v[idx]);

	if (v[idx] == 'a' || v[idx] == 'e' || v[idx] == 'i' ||
		v[idx] == 'o' || v[idx] == 'u')
		mo_cnt++;
	else
		ja_cnt++;

	if (str.length() == l && mo_cnt > 0 && ja_cnt > 1) {
		cout << str << '\n';
		return;
	}

	for (int i = idx + 1; i < c; i++) {
		back(i, mo_cnt, ja_cnt);
		str.pop_back();
	}
}

int main() {
	cin >> l >> c;

	for (int i = 0; i < c; i++) {
		char input;
		cin >> input;
		v.push_back(input);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i <= c - l; i++) {
		str = "";
		back(i, 0, 0);
	}
}
