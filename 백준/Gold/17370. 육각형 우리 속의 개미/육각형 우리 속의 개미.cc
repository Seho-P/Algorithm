#include <iostream>

using namespace std;

int N;
int answer;
int visited[101][101];
// 0: 아래
// 1: 오른쪽 아래
// 2: 오른쪽 위
// 3: 위
// 4: 왼쪽 위
// 5: 왼쪽 아래
int dy[] = {1,1,-1,-1,-1,1};
int dx[] = {0,1,1,0,-1,-1};



void dfs(int y,int x,int dir,int move){
    if (visited[y][x]) {
        if (move == 0) answer++;
            return;
    }
    if (move == 0) return;

    
    int right_dir = (dir+1)%6;
    int left_dir  = (dir+5)%6;
    visited[y][x] = 1;
    dfs(y+dy[left_dir],x+dx[left_dir],left_dir,move-1);
    dfs(y+dy[right_dir],x+dx[right_dir],right_dir,move-1);
    visited[y][x]=0;
}

int main() {
	ios::sync_with_stdio(0); 
    cin.tie(0);
	cin >> N;

	visited[49][50] = 1;
	dfs(50, 50, 0, N);
	
	cout << answer << "\n";
	return 0;
}
