#include <iostream>
using namespace std;

int chess[501][501];
int parent[501][501];
int result[501][501];
int dx[8] = {1,1,0,-1,-1,-1,0,1};
int dy[8] = {0,-1,-1,-1,0,1,1,1};

int r, c;

// parent를 1차원 인덱스로 관리
int find_parent(int x) {
    int px = x / c;
    int py = x % c;
    if (parent[px][py] == x) return x;
    return parent[px][py] = find_parent(parent[px][py]); // path compression
}

void union_cell(int x, int y) {
    int px = find_parent(x);
    int py = find_parent(y);
    if (px != py) parent[py / c][py % c] = px;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> chess[i][j];
            parent[i][j] = i * c + j; // 초기엔 자기 자신이 루트
        }
    }

    // 각 칸마다 가장 낮은 인접 칸으로 union
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            int minVal = chess[i][j];
            int nx = i, ny = j;
            for (int k = 0; k < 8; k++) {
                int xx = i + dx[k];
                int yy = j + dy[k];
                if (xx >= 0 && xx < r && yy >= 0 && yy < c) {
                    if (chess[xx][yy] < minVal) {
                        minVal = chess[xx][yy];
                        nx = xx; ny = yy;
                    }
                }
            }
            if (nx != i || ny != j) {
                union_cell(nx * c + ny, i * c + j);
            }
        }
    }

    // 각 칸이 최종적으로 도착하는 루트를 찾아 결과 기록
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            int p = find_parent(i * c + j);
            result[p / c][p % c]++;
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }
}