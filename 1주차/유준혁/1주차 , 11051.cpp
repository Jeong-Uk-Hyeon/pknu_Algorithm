#include <iostream>
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 1001 // �迭 ũ��, ���� ���ǿ� �°� ����
#define MOD 10007 // ��ⷯ ��

using namespace std;

int pascal[SIZE][SIZE];
int main() {
    fastio;
    int N, K;
    cin >> N >> K;

    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (j == 0 || j == i) {
                pascal[i][j] = 1;
            }
            else {
                pascal[i][j] = (pascal[i - 1][j - 1] + pascal[i - 1][j]) % MOD;
            }
        }
    }
    cout << pascal[N][K] << endl;

    return 0;
}
