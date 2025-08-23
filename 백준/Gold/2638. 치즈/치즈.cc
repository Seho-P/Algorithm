#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;

int allc[101][101];
int allair[101][101];
int n,m;
bool allempty = true;

int x[4] = {0,0,-1,1};
int y[4] = {1,-1,0,0};

int visited[101][101];



void bfsempty(){
    
    queue<pair<int,int>> q;
    q.push({0,0});
    while(!q.empty()){
        pair<int,int> xy = q.front();
        q.pop();
        if(visited[xy.first][xy.second])continue;
        visited[xy.first][xy.second] = 1;
        allc[xy.first][xy.second] = -1;
        for(int i=0;i<4;i++){
        int yy = xy.first+y[i];
        int xx = xy.second+x[i];
        if(xx<0 || xx>=m || yy <0 || yy>=n)continue;
        if (allc[yy][xx]==1)
        {
            allair[yy][xx]++;
        }
        
        else if(visited[yy][xx]==0){
            q.push({yy,xx});
        }
        
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tem;
    int cnt = 0;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int p=0;p<m;p++){
            cin >> tem;
            allc[i][p] = tem;
        }
    }
    bool realchease = true;
    while(1){
        memset(allair,0,sizeof(allair));
        memset(visited,0,sizeof(visited));
        bfsempty();
        for(int i=0;i<n;i++){
            for(int p=0;p<m;p++){
                if(allair[i][p]>=2){
                    realchease = false;
                    allc[i][p]=-1;
                }
            }
        }
        if(realchease){
            break;
        }
        realchease = true;
        cnt++;  
    }
    cout << cnt;
    

}