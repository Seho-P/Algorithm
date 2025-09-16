#include <iostream>
#include <queue>
using namespace std;

int visited[21][21];
int badukpan[21][21];
bool liveb;
int maxdie = 0;
int k =0;

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

void baduk2(int n,int m){
    queue<pair<int,int>> bwq;
    int tem = 0;
    for(int i=0;i<n;i++){
        for(int p=0;p<m;p++){
            if(badukpan[i][p]==2 && visited[i][p]==0){
                liveb = false;
                int bcnt = 0;
                bwq.push({i,p});
                visited[i][p]=1;
                while(!bwq.empty()){
                    int x = bwq.front().first;
                    int y = bwq.front().second;
                    bwq.pop();
                    bcnt++;
                    for(int r=0;r<4;r++){
                        int xx = dx[r]+x;
                        int yy = dy[r]+y;
                        if(xx<0 || xx>=n || yy<0 || yy>=m || visited[xx][yy]==1)continue;
                        if(badukpan[xx][yy]==2){
                            bwq.push({xx,yy});
                            visited[xx][yy] = 1;
                        }
                        else if(badukpan[xx][yy]==0){
                            liveb=true;
                        }
                    }
                }
                if(!liveb){
                    tem+=bcnt;
                }
            }
        }
    }
    if(maxdie<tem){
        maxdie = tem;
    }
}

void resetvisit(int n,int m){
    for(int i=0;i<n;i++){
        for(int p=0;p<m;p++){
            visited[i][p] = 0;
        }
    }
}

int main(){
    int n,m;
    cin >> n >> m;
    
    for(int i=0;i<n;i++){
        for(int p=0;p<m;p++){
            cin >> badukpan[i][p];
        }
    }
    for(int i=0;i<n;i++){
        for(int p=0;p<m;p++){
            for(int r=0;r<n;r++){
                for(int e=0;e<m;e++){
                    if(badukpan[i][p] == 0 && badukpan[r][e] == 0){
                        badukpan[i][p] = 1;
                        badukpan[r][e] = 1;
                        baduk2(n,m);
                        badukpan[i][p] = 0;
                        badukpan[r][e] = 0;
                        resetvisit(n,m);
                    }
                }
            }
            
        }
    }
    cout << maxdie;
}