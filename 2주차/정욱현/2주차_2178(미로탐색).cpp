#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)

#define SIZE 103

int n, m, visit[SIZE][SIZE];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1}; // xy �����¿� �˻��ϱ� ���� ���� ��Ƴ��� �迭  
char arr[SIZE][SIZE];
queue<pair<int, int> > q; // int2���� ���� ������ ������ ť�� ����  

int main(){
	fastio;
	cin >> n >> m; // �̷��Է¹��� 
	for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
	
	q.push({0, 0}); // ť�� ������� �ְ� ���� 
	visit[0][0] = 1;
	while (!q.empty()){
		auto [x, y] = q.front(); // �����¿� �˻��� ��ġ x, y�� ť���� ������  
		q.pop();
		for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || arr[nx][ny] == '0' || visit[nx][ny] <= visit[x][y] + 1) continue;
            // �� ���ǽ� ť�� ��ġ �ʴ´� visit[][]������ �̹� ���ٿ� ���� �����ؼ� ���ٿ� ���� ť�� ���� �ʵ��� �Ѵ�  
            q.push({nx, ny}), visit[nx][ny] = visit[x][y] + 1; // �� ������ �����ϸ� ť�� �ִ´�  
        }
	} 
	
	cout << visit[n][m];
return 0;
}

