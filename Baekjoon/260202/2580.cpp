#include <iostream>
#include <vector>

using namespace std;

int board[9][9];
vector<pair<int, int>> zero;

bool check(int x, int y, int n) {
    for (int i = 0; i < 9; i++) {
        if (board[x][i] == n) return false;
    }

    for (int i = 0; i < 9; i++) {
        if (board[i][y] == n) return false;
    }

    int start_x = (x / 3) * 3;
    int start_y = (y / 3) * 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[start_x + i][start_y + j] == n) return false;
        }
    }

    return true;
}

void solve(int idx) {
    if (idx == zero.size()) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
        exit(0);
    }

    int x = zero[idx].first;
    int y = zero[idx].second;

    for (int k = 1; k <= 9; k++) {
        if (check(x, y, k)) {
            board[x][y] = k;
            solve(idx + 1);
            board[x][y] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
            if (board[i][j] == 0) {
                zero.push_back({ i, j });
            }
        }
    }

    solve(0);
}
