#include <iostream>
#include <vector>
using namespace std;

int n;
int result = 0;
int visitedCount = 0;
int visited[100001];
vector<pair<int,int>> tree(100001);

void dfs(int x) {
    int L = tree[x].first;
    int R = tree[x].second;

    // 왼쪽 자식
    if (L != -1 && visited[L] == 0) {
        result++;           // L로 이동
        dfs(L);
        result++;           // 다시 x로 복귀
    }

    // 자기 자신 방문
    if (!visited[x]) {
        visited[x] = 1;
        visitedCount++;

        // 모든 노드 방문 완료 → 출력 후 종료
        if (visitedCount == n) {
            cout << result;
            return;
        }
    }

    // 오른쪽 자식
    if (R != -1 && visited[R] == 0) {
        result++;
        dfs(R);
        result++;
        // 여기서는 복귀를 증가시키지 않음 (마지막 노드면 복귀하지 않기 때문)
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0, a, b, c; i < n; i++) {
        cin >> a >> b >> c;
        tree[a] = {b, c};
    }

    dfs(1);
    return 0;
}
