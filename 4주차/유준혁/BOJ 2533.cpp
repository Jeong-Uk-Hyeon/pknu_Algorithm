#include <bits/stdc++.h>
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 1'000'003
using namespace std;

vector<int> vec[SIZE];
int n, m, vis[SIZE], res, dp[SIZE][2];


// �󸮾���Ͱ� �־����� ����. ������ ����϶�, �ƴҶ��� ����
// �ּ� �󸮾� ���� �� : dp �ּҰ����� �ؾ���. => min()
// ���� ��� dp�迭 Ȱ�� > SIZE��ŭ�� dp�� 2������ ���� ����. dp[SIZE][2];
// dp[SIZE][0] = ������ �󸮾������ ��
// dp[SIZE][1] = ������ �󸮾���Ͱ� �ƴҶ�
void DFS(int now, int prev) {
    vis[now] = 1;
    dp[now][0] = 0;
    dp[now][1] = 1;
    for (auto nxt : vec[now]) {
        if (nxt == prev) continue;
        if (vis[nxt] == 1) continue;
        DFS(nxt, now);

        dp[now][0] += dp[nxt][1]; // ���� ������ �󸮾���� X -> ����(�ڽ�) �� �ֺ� ���� �󸮾���Ϳ�����. ��Ʈ���� ���� �������� �ڵ�¥��
        dp[now][1] += min(dp[nxt][0], dp[nxt][1]); // ���� ������ �󸮾���Ͷ�� �ֺ����� ���� ���� �ְ�, �ƴ� ���� ����. ���� �ּҰ��� ���ϴ� ����
        //�ᱹ �������� ����ϴ� dp[value][0]�� dp[value][1]�� ������ ���(��Ʈ)�� ����϶� �ƴҶ�, �� ��� ��찡 ������ ������ ������ �̷����
    }
}

int main() {
    fastio;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    //1�� ��Ʈ�� ��� ��͸� ���� 1�� ���� �������� ����. ���� �� ��¶��� dp[1]���� ����ϸ� ��.
    DFS(1, -1);
    cout << min(dp[1][0], dp[1][1]);
    return 0;
}
