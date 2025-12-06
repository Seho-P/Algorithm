#include <iostream>

using namespace std;

int N;
int answer;
int visited[101][101];
int dy[] = {1,1,-1,-1,-1,1};
int dx[] = {0,1,1,0,-1,-1};

//oxo
//xox
//xox
//oxoxC
//oxox
//xoxo

// 이러면 right +1계속 해주면 잘 돌아감
// left는 +5 ㅇㅋ 이거다 

void dfs(int y,int x,int dir,int move){
    if(move==0){
        if(visited[y][x]==0)return;
        answer++;
        return;
    }
    else if(visited[y][x]==1)return;
    
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