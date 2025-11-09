#include <iostream>
using namespace std;

int n;
int result = 0;
bool col[16];       // 각 열에 퀸이 있는지
bool diag1[32];     // ↙↗ 방향 (r+c) , 왼쪽 위부터 계산 
bool diag2[32];     // ↘↖ 방향 (r-c+n-1),오른쪽 위부터 계산

void dfs(int row) {
    if (row == n) {
        result++;
        return;
    }

    for (int c = 0; c < n; c++) {
        if (col[c] || diag1[row + c] || diag2[row - c + n - 1])
            continue;  // 공격 가능 위치면 skip

        col[c] = diag1[row + c] = diag2[row - c + n - 1] = true;
        dfs(row + 1);
        col[c] = diag1[row + c] = diag2[row - c + n - 1] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    dfs(0);
    cout << result;
}