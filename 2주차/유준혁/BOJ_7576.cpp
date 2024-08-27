#include <iostream>
#include <queue>
using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 1'003

int m, n;
int arr[SIZE][SIZE];
int dist[SIZE][SIZE]; // �ʹ� �� �ɸ��� �ϼ��� ����
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
queue<pair<int, int>> q;

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> arr[i][j];
            if (arr[i][j] == 1) {
                q.push({ i, j });
                dist[i][j] = 0; // ���� �丶���� �ʱ� �Ÿ��� 0
            }
            else if (arr[i][j] == 0) {
                dist[i][j] = -1; // ���� ���� ���� �丶��� -1�� �ʱ�ȭ
            }
        }
    }

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if (dist[nx][ny] >= 0) continue; // �̹� �湮�߰ų� ��(arr=-1, dist = 0)�̸� ��ŵ

            dist[nx][ny] = dist[x][y] + 1;
            q.push({ nx, ny });
        }
    }

    int result = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dist[i][j] == -1) {
                cout << -1 << '\n';
                return 0;
            }
            result = max(result, dist[i][j]);
        }
    }

    cout << result << '\n';
    return 0;
}






/*while (!q.empty()) {
	int cu_x = q.front().first;
	int cu_y = q.front().second;
	q.pop();
	for (int i = 0; i < 4; ++i) {
		int nx = cu_x + dx[i];
		int ny = cu_y + dy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m || vis[nx][ny] != 0) continue; // ������ ����ų� �湮�� ���̸� ť�� ���� X
		q.push({ nx, ny }), vis[nx][ny] = 1;
	}
} ���� �������� �߻��ϴ� ��쵵 ����. �� �ڵ�� �� ������ ���� �丶�䰡 ���� ��츸 �ش�.
*/