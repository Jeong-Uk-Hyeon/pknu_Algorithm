#include <bits/stdc++.h>
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 503
using namespace std;

int n, m, dp[SIZE][SIZE], grid[SIZE][SIZE];
int res = 0;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int DFS(int x, int y) {
    //dp�迭�̶� ������� �Ǵٰ� 0,0���� ������ ��, �� �� �ִ� ����� ���� �����ϰ��ִ� �迭�̴�.
    //����, ��������� �����ϵ� �ϴ� dp �迭 �ε����� ���� -1�� �ƴ� �ٸ����̶�� �� ����, �� �� �ִ� �ִ� ����� ���� �̹� �����ϰ��ִ� ����
    //���� dp[0][0] ���� 3�̶�� dp[1][0]���� dp[0][0]���� �����ϸ� �� �ڷδ� ��� �� �ʿ䰡 ���ٴ� ��
    //dp[x][y] ���� ������� �����Ƿ� �ش� �ε��� ���� �ٷ� ��ȯ �� > +1�ؼ� dp[1][0]�� ����
    //�ƴ� �ٵ� �� �ȵ�
    if (dp[x][y] != -1) return dp[x][y];
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 1 || nx > n || ny < 1 || ny > n)
            continue;
        if (grid[x][y] < grid[nx][ny])
            dp[x][y] = DFS(nx, ny) + 1;
    }

    return dp[x][y];
}

int main() {
    fastio;
    cin >> n;

    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> grid[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            // (1,1)���� (n,n)���� dfs �ǽ�. dp�迭 �̿��ؼ� �̹� ����Ǿ��ִ� �� Ȱ���ؼ� ��� �ڸ����� �����ϴ� ��� ���
            res = max(res, DFS(i, j));
            // �ᱹ dp�迭�� ���� ū ���� ã���� �Ǵ°��� �ƴѰ�
            // �� 0�� ��������,,
        }
    }
    cout << res;

    return 0;
}