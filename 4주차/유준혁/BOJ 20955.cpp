#include <bits/stdc++.h>
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 100'003
using namespace std;

vector<int> vec[SIZE]; // first = ������ ��� ����, second = dep
int n, m, compo, vis[SIZE], res, cnt;
bool isCycle[SIZE];

// �ᱹ �ó���(Ʈ��)�� ���� - 1 �� res ���� ���� ������.
// �ó����� 2�� �� �� > res = 1
// �ó����� 3�� �� �� > res = 2
// �ó����� 4�� �� �� > res = 3
// > ���� ����Ŭ�� ������ ���� ����
// ����Ŭ 1�� �߻� > 1�� �۾� | 2�� �߻� > 2�� �۾�
// ����Ŭ�� ���� + �̾��� ���� �ʴ� ���(4, 5, 6)�� ���� ���ϸ� ���� �� ��.
// ����Ŭ�� ���� ������ ���� ������ ����.
// ���������� �����µ� ��Ʋ����
// ����Ŭ ������ �迭�� �����.
void DFS(int now, int prev) {
    vis[now] = 1;
    for (auto nxt : vec[now]) {
        if (!vis[nxt]) DFS(nxt, now); // ��(�θ���)���� �湮�� ���� ����. == Ʈ���̴�.
        // �湮�� ���� ������ �ٷ� �� ��� ���� �ƴ� �� = ����Ŭ�̴�. + ó�� ����Ŭ�� �߰� �� ���
        else if (!isCycle[nxt] && nxt != prev) cnt += 1;
    }
    isCycle[now] = true;
}

int main() {
    fastio;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            DFS(i, -1);
            res += 1;
        }
    }
    cout << res - 1 + cnt;
    return 0;
}
