#include <iostream>
using namespace std;

int chess[16][16];
int qcnt;
int result;
int qc[16];
pair<int,int> temc[16];
int dx[4] = {-1,-1,1,1};
int dy[4] = {1,-1,-1,1};

bool checkqueen(int n,int x,int y){
    for(int i=0;i<8;i++){
        temc[i] = {x+dx[i],y+dy[i]};
    }
    for(int i=0;i<4;i++){
        while(temc[i].first>=0 && temc[i].second>=0 && temc[i].first<n &&temc[i].second<n){
            if(chess[temc[i].first][temc[i].second]==1){
                return false;
            }
            temc[i] = {temc[i].first+dx[i],temc[i].second+dy[i]};
        }
    }
    return true;
}


void dfs(int n,int rank){
    if(rank==n){
        result++;
        return;
    }
    for(int i=0;i<n;i++){
        if(qc[i]!=1 &&checkqueen(n,rank,i)){
            chess[rank][i]=1;
            qc[i]=1;
            qcnt++;
            dfs(n,rank+1);
            chess[rank][i]=0;
            qcnt--;
            qc[i]=0;
        }
        
    }
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    dfs(n,0);
    cout << result;
}