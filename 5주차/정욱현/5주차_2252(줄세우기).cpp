#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)

#define SIZE 32'003

int n, m;
int ind[SIZE]; // ��������
vector<int> adj[SIZE];
queue<int> q;

int main(){
    fastio;
    cin >> n >> m;
    while (m--) { // �Է��� �޾� �������� �����
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        ind[b]++;
    }

    for (int i = 1; i <= n; i++) // ���������� ���ǿ� �°� ��� �ϳ��� Ž���ϱ�
        if (!ind[i])// ���������� 0�̶�� �ʱ� ��߳��� ť�� �ֱ�
            q.push(i);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        cout << cur << ' ';
        for (auto nxt: adj[cur]) { //������� for�ݺ� �̹��� ����� ���� ����� ��� ��忡 ���� �ݺ�
            ind[nxt]--; // ����� ��� ����� ������ 1�� ����
            if (!ind[nxt]) q.push(nxt);
        }
    }
    return 0;
}
