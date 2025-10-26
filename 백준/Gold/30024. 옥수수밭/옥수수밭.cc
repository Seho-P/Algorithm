#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int corn[1001][1001];
int visited[1001][1001];
pair<int,int> cornidx[1000001];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int main(){
    int n,m,k;
    cin >> n >> m;
    priority_queue<int> poscorn;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> corn[i][j];
            if(i==1 || j==1 || i==n || j==m){
                visited[i][j]=1;
                poscorn.push(corn[i][j]);
            }
            cornidx[corn[i][j]]={i,j};
            
        }
    }
    cin >> k;
    visited[cornidx[poscorn.top()].first][cornidx[poscorn.top()].second] = 1;
    while(k--){
        auto l = poscorn.top();
        poscorn.pop();
        cout << cornidx[l].first <<" " << cornidx[l].second << "\n";
        for(int i=0;i<4;i++){
            int xx = cornidx[l].first + dx[i];
            int yy = cornidx[l].second + dy[i];
            if(xx<1 || xx>n || yy<1 || yy>m)continue;
            if(!visited[xx][yy]){
                visited[xx][yy] = 1;
                poscorn.push(corn[xx][yy]);
            }
            
        }
    }
}