#include <iostream>
#include <queue>
using namespace std;

int n,m;
int all[1000][1000];
int visited[1000][1000][2];

struct ff{
    int a,b;
    int wall;
    int dist;
};

int x[4] = {0,0,-1,1};
int y[4] = {1,-1,0,0};

void bfs(){
    queue<ff> route;
    route.push({0,0,0,1});
    visited[0][0][0] = 1;
    while(!route.empty()){
        ff tem = route.front();
        route.pop();
        if(tem.a==n-1 && tem.b ==m-1){
            cout << tem.dist;
            return;
        }
        for(int i=0;i<4;i++){
            int xx = x[i]+tem.a;
            int yy = y[i]+tem.b;
            if(xx<0 || xx>=n || yy<0 || yy>=m)continue;
            if(all[xx][yy]==1 && tem.wall == 0 && !visited[xx][yy][1]){
                visited[xx][yy][1] = 1;
                route.push({xx,yy,1,tem.dist+1});
            }
            if(all[xx][yy]==0 && !visited[xx][yy][tem.wall]){
                visited[xx][yy][tem.wall] = 1;
                route.push({xx,yy,tem.wall,tem.dist+1});
            }
        }

    }
    cout << -1;
    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        string row;
        cin >> row;
        for(int p=0;p<m;p++){
            all[i][p] = row[p] - '0';
        }
    }
    bfs();
}