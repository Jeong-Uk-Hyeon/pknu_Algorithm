#include <iostream>
#include <cstring>
using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 100'003

int t, n, ans;
int pick[SIZE];
bool vis[SIZE];
bool done[SIZE];

void dfs(int now) {
	vis[now] = true;
	int next = pick[now];
	
	if (!vis[next]) dfs(next); // �湮 X, ���� ���� ���ȣ��
	else if (!done[next]) { // �湮�� �Ǿ����� ����Ŭ�� ���ԵǾ� ���� ���� ���
		for (int i = next; i != now; i = pick[i]) {
			ans++; // ����Ŭ�� ũ�� ����
		}
		ans++; // ����Ŭ ���� ��� ����
	}
	done[now] = true; // ���� ��带 ����Ŭ�� ����
}

int main() {
	cin >> t;
	while(t--) {
		memset(vis, false, sizeof(vis)); //������ ���� ���Ӱ� �˰� ��.
		memset(done, false, sizeof(done)); // �ش� �迭�� sizeof ����Ʈ�� false�� ��� �ʱ�ȭ. �� ������� ����Ŭ ���� �� ����
		ans = 0;
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> pick[i];
		}
		for (int i = 1; i <= n; ++i) {
			if (vis[i]) continue; // �̹� �湮�ߴٸ� �ǳʶٱ�
			dfs(i);
		}
		cout << n - ans << "\n"; // ��ü �ο����� ����Ŭ�� �ش��ϴ� ��(�ش�Ǵ� �ο� ��)��ŭ ����
	}
	return 0;
}