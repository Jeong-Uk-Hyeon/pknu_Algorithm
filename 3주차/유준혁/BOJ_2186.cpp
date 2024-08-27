#include <bits/stdc++.h>
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 103
using namespace std;

int n, m, k, dp[SIZE][SIZE], grid[SIZE][SIZE];
string word;
int res = 0;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int DFS(int x, int y, int idx) {
    if (dp[x][y] != -1) return dp[x][y];
    if (idx > word.length()) return 1;
    for (int i = 0; i < 4; ++i) {
        for (int j = 1; j <= k; ++j) {
            // k���� ĭ ���� �̵������ϱ� ������ for�� �ۼ�
            int nx = x + dx[i] * k;
            int ny = y + dy[i] * k;
            if (nx < 1 || nx > n || ny < 1 || ny > n)
                continue;
            if (grid[x][y] != word[idx]) continue;
            //dp�迭�� ���� �н� �ʿ�....
            dp[x][y] = DFS(nx, ny, idx + 1);
        }
    }

    return dp[x][y];
}

int main() {
    fastio;
    cin >> n >> m >> k;

    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> grid[i][j];
        }
    }
    cin >> word;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
        }
    }
    cout << res;

    return 0;
}
