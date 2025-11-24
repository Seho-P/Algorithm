#include <iostream>
using namespace std;

int doro[501][501];
int dp[501][501];
int m,n;

int dx[4] = {1,0,0,-1}; 
int dy[4] = {0,1,-1,0};

int dfs(int y,int x){
    if(y==m-1 && x==n-1)return 1;
    if(dp[y][x]!=-1) return dp[y][x];
    dp[y][x]=0;
    for(int i=0;i<4;i++){
        int xx = x+dx[i];
        int yy = y+dy[i];
        if(xx<0 || xx>=n || yy<0 || yy>=m)continue;
        if(doro[y][x]>doro[yy][xx]){
                dp[y][x] = dp[y][x] + dfs(yy,xx);
        }
    }
    return dp[y][x];
}

int main(){
    cin >> m >> n;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin >> doro[i][j];
            dp[i][j]=-1;
        }
    }
    dfs(0,0);
    cout << dp[0][0];
}


// dfs + parent기억해서 풀엇을듯 