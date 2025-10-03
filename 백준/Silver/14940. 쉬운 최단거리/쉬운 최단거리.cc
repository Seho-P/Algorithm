#include <iostream>
#include <queue>
using namespace std;

int sp[1002][1002];
int visited[1002][1002];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int main(){
    int n,m;
    int startx,starty;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> sp[i][j];
            if(sp[i][j]==2){
                startx=i;
                starty=j;
                visited[i][j]=1;
                sp[i][j]=0;
            }
            else if(sp[i][j]==0){
                visited[i][j]=1;
            }
        }
    }
    queue<pair<int,int>> pq;
    pq.push({startx,starty});
    while(!pq.empty()){
        int x = pq.front().first;
        int y = pq.front().second;
        pq.pop();
        for(int i=0;i<4;i++){
            int xx = x+dx[i];
            int yy = y+dy[i];
            if(xx<0 || xx>=n || yy<0 || yy>=m || visited[xx][yy]==1)continue;
            pq.push({xx,yy});
            visited[xx][yy]=1;
            sp[xx][yy]=sp[x][y]+1;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(visited[i][j]==1){
                cout << sp[i][j] << " ";
            }
            else{
                if(sp[i][j]==1){
                    cout << -1 << " ";
                }
            }
        }
        cout << endl;
    }
}