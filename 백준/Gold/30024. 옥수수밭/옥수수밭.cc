#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int corn[1001][1001];
int visited[1001][1001];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,k;
    cin >> n >> m;

    priority_queue<pair<int, pair<int,int>>> poscorn;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> corn[i][j];
            if(i==1 || j==1 || i==n || j==m){
                // 초기에는 visited 표시하지 않음
                poscorn.emplace(corn[i][j], make_pair(i,j));
            }
        }
    }
    cin >> k;

    int printed = 0;
    while(printed < k && !poscorn.empty()){
        auto cur = poscorn.top();
        poscorn.pop();
        int x = cur.second.first;
        int y = cur.second.second;

        if(visited[x][y]) continue; // 이 경우 printed를 증가시키지 않음

        visited[x][y] = 1;
        cout << x << " " << y << '\n';
        printed++;

        for(int i=0;i<4;i++){
            int xx = x + dx[i];
            int yy = y + dy[i];
            if(xx<1 || xx>n || yy<1 || yy>m) continue;
            if(!visited[xx][yy]){
                poscorn.emplace(corn[xx][yy], make_pair(xx,yy));
            }
        }
    }
    return 0;
}