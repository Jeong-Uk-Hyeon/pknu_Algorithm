#include <bits/stdc++.h>

using namespace std;

#include <bits/stdc++.h>

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)

#define SIZE 503

int n, m, x, y;
int vis[SIZE];
bool isTree;
vector<int> adj[SIZE]; //����� ����Ʈ�� ������ ǥ�� SIZE���� ��Ҹ� ���� �� �ִ� adj �迭�� ����
//�ȿ� ���� ��Ҵ� vector<int> int�� ��ҷ� ������ �����迭 vector

void DFS(int now, int prev){ // Ʈ������ �ƴ����� �Ǵ��ϴ� �Լ�
    vis[now] = 1;
    for (int nxt : adj[now]) { // ������� for���� ����
        if(nxt == prev) continue; // ���������� ������ Ž���� ����
        if(vis[nxt]){ // �̾��� ��尡 �̹� �湮�Ǿ��°� �� ����Ŭ�� �ֳ�
            isTree =  false;
            continue; // ����Ŭ�� �߰��� Ʈ���� �ƴѰ��� �˾Ƶ� ������ Ž���ؾ� �� Ʈ�������� ������
        }
        DFS(nxt,now);
    }
}

int main(){
    fastio;
    while(1) {
        cin >> n >> m;
        if (!n && !m) break;
        for (int i = 1; i < SIZE; i++)
            adj[i].clear();
        fill(vis, vis + SIZE, 0);

        while(m--) {
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        int res = 0;
        for (int i = 1; i <= n; i++) {
            isTree = true;
            DFS(i, -1);
            res += isTree;
        }
        cout << res << '\n';
    }
    return 0;
}
