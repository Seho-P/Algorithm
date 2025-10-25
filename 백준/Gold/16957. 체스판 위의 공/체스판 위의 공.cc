#include <iostream>
#include <queue>
using namespace std;

int chess[501][501];
int visited[501][501];
int parent[501][501];
int result[501][501];

int dx[8] = {1,1,0,-1,-1,-1,0,1};
int dy[8] = {0,-1,-1,-1,0,1,1,1};

int dfs(int r,int c,int mr,int mc){
    if(visited[r][c])return parent[r][c];
    
    visited[r][c]=1;
    int temchess = chess[r][c];
    int mintem = temchess;
    int nextr=r,nextc=c;
    for(int i=0;i<8;i++){
            int xx = r+dx[i];
            int yy = c+dy[i];
            if(xx>=0 && xx<mr && yy>=0 && yy<mc){
                if(mintem>chess[xx][yy]){
                mintem = chess[xx][yy];
                nextr=xx,nextc=yy;
                }
            }
        }
    if(temchess!=mintem){
        parent[r][c] = dfs(nextr,nextc,mr,mc);
    }
    else{
        parent[r][c]=r*mc+c;
    }
    return parent[r][c];
}

int main(){
    int r,c;
    cin >> r >> c;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> chess[i][j];
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(!visited[i][j]){
                dfs(i,j,r,c);
            }   
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            result[parent[i][j]/c][parent[i][j]%c]++;
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }
}