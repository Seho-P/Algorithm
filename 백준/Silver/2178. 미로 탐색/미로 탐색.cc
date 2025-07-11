#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int miro[101][101];
queue<pair<int,int>> q;
int xpos[4] = {0,0,-1,1};
int ypos[4] = {1,-1,0,0};

int bfs(int n,int m){
    while(!q.empty()){
        pair<int,int> tem = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int xx = xpos[i] + tem.first;
            int yy = ypos[i] + tem.second;
            if(xx<0 || yy<0 || xx>=m || yy>=n) continue;
            if(0 < miro[xx][yy] && miro[xx][yy]< miro[tem.first][tem.second]+1){
                q.push({xx,yy});
                miro[xx][yy] = miro[tem.first][tem.second]+1;
                if(xx == m-1 && yy == n-1){
                    return miro[xx][yy];
                }
            }
            
        }
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    string tem;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> tem;
        for(int p=0;p<m;p++){
            miro[p][i] = int(tem[p])-48;
        }
    }
    q.push({0,0});
    cout << bfs(n,m) << "\n";
}